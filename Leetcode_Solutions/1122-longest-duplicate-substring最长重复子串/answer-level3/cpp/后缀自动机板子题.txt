看了一圈题解看到了sa没看到sam，水一发
sam上拓扑排序一下，只要出现次数>=2的都是符合题意要求的，取其中最大的便是答案
```
class Solution {
public:
    #define kind 26
    #define maxn 100005
    struct state
    {
        state *Next[kind],*link;
        int len;
        int cnt;
        int idx;
        state()
        {
            idx=0;
            cnt=0;
            link=0;
            len=0;
            memset(Next,0,sizeof Next);
        }
    };
    class sam
    {
    public:
        int sz;
        state st[maxn*2];
        int in[maxn*2];
        inline state* newnode(int len=0)
        {
            memset(st[sz].Next,0,sizeof(st[sz].Next));
            st[sz].link=0;
            st[sz].len=len;
            st[sz].cnt=1;
            st[sz].idx=sz;
            return &st[sz++];
        }
        state *root,*last;
        void extend(int w,int id)
        {
            state* p=last;
            state* cur=newnode(p->len+1);
            cur->idx=id;
            while(p&&p->Next[w]==0)
            {
                p->Next[w]=cur;
                p=p->link;
            }
            if(p)
            {
                state* q=p->Next[w];
                if(p->len+1==q->len)
                    cur->link=q;
                else
                {
                    state* clone=newnode(p->len+1);
                    memcpy(clone->Next,q->Next,sizeof(q->Next));
                    clone->link=q->link;
                    clone->idx=id;
                    q->link=clone;
                    cur->link=clone;
                    clone->cnt=0;
                    while(p&&p->Next[w]==q)
                    {
                        p->Next[w]=clone;
                        p=p->link;
                    }
                }
            }
            else cur->link=root;
            last=cur;
        }
        void init()
        {
            sz=0;
            memset(in,0,sizeof in);
            root=newnode();
            last=root;
        }
        void calc()
        {
            for(int i=sz-1;i>=1;i--)
                st[i].link->cnt+=st[i].cnt;
        }
    }A;
    string longestDupSubstring(string S)
    {
        A.init();
        for(int i=0;i<S.size();i++) A.extend(S[i]-'a',i);
        A.calc();
        int mx=0;
        int r;
        for(int i=1;i<A.sz;i++)
        {
            if(A.st[i].cnt>=2)
            {
                if(A.st[i].len>mx)
                {
                    r=A.st[i].idx;
                    mx=A.st[i].len;
                }
            }
        }
        string ret;
        if(mx==0) return ret;
        for(int i=r-mx+1;i<=r;i++) ret.push_back(S[i]);
        return ret;
    }
};
```

