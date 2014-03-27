#ifndef TRIE_H
#define TRIE_H

#include <QObject>

class Trie : public QObject
{
    struct node
    {
        node *nxt[133];
        bool ed;
        void clear(){memset(nxt,0,sizeof nxt);ed=false;}
    }*root;

    std::vector<std::string>ans;
    std::string ts;
    void insert(const char *str);
    int pdc(const char *s);

    Q_OBJECT
public:
    explicit Trie(QObject *parent = 0);
    void init();
public slots:
    bool go(const QString &str);
    bool go(const char *str);
    QString get()const;
};

#endif // TRIE_H
