#include<string>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<cstring>

#include<Qfile>
#include<QDebug>

#include "trie.h"

std::string buff;
void strip(std::string &str)
{
    static int i;
    for(i=0;str[i] && !isspace(str[i]);++i);
    str[i]=0;
}

Trie::Trie(QObject *parent) : QObject(parent) { }

void Trie::init()
{
    root=new node();
    root->clear();

    QFile file(":/new/prefix1/dic");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"Can't open dictionary file";
        exit(1);
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString ln=in.readLine();
        buff=ln.toStdString();
        strip(buff);
        insert(buff.c_str());
    }
    qDebug()<<"init finished";
}
void Trie::insert(const char *str)
{
    static int i,c;
    static node *p;
    p=root;
    for(i=0;str[i];++i)
    {
        if(!p->nxt[c=-str[i]])
        {
            p->nxt[c]=new node();
            p->nxt[c]->clear();
        }
        p=p->nxt[c];
    }
    p->ed=true;
}

int Trie::pdc(const char *s)
{
    static int last,i;
    static node *p;
    p=root;
    i=0;
    last=-1;
    while(s[i] && p->nxt[-s[i]])
    {
        p=p->nxt[-s[i++]];
        if(p->ed)
            last=i;
    }
    return last;
}
bool Trie::go(const QString &str) { return go(str.toStdString().c_str()); }
bool Trie::go(const char *str)
{
    static int i,j;
    ans.clear();
    if(strlen(str)%3)
        return false;
    for(i=0;str[i];++i)
        if(str[i]>=0)
            return false;
    while(*str)
    {
        ts.clear();
        j=pdc(str);
        if(j==-1)
        {
            ts.push_back(str[0]);
            ts.push_back(str[1]);
            ts.push_back(str[2]);
            str+=3;
        }
        else
        {
            for(i=0;i<j;++i)
                ts+=str[i];
            str+=j;
        }
        ans.push_back(ts);
    }
    ts.clear();
    for(i=0;i<(int)ans.size();++i)
    {
        ts+=ans[i];
        if(i+1!=(int)ans.size())
            ts+=' ';
    }
    return true;
}
QString Trie::get()const
{
    return QString::fromStdString(ts);
}
