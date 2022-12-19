题目要求让最后构造的字符串尽量长，从aabaa这个样例就可以看出来，如果不能把所有a,b,c放完，那么一定是在较多的字母中间插入其他字母。
思路也就很显然，从空串开始，每次都尝试在最后插入当前剩的最多的字母，如果当前串最后两个字母一样，就不能再插入这个字母，换为插入剩下的两种中，较多的那一种。
不过如果我们直接写，就会每次都要判断哪一个最少，还要判断剩下两种多。if就会特别多，不仅写起来麻烦，改bug也会很难受。所以就考虑将字母和出现次数用结构体存起来，然后每次做完sort一下，这样最大值下标固定，还可以用循环处理，代替多个if，看起来就更简洁优雅（个人觉得）。
```
class Solution {
    struct Node{
        int num;
        char ch;
        Node(int num=0,char ch=' '):num(num),ch(ch){}
        bool operator < (const Node &rhs)const{
            return num<rhs.num;
        }
    }a[4];
    string res;//要返回的字符串
    void add(int pos){////往res最后加入下表为pos对应的字符
        res+=a[pos].ch;
        --a[pos].num;
        sort(a+1,a+4);
    }
public:
    string longestDiverseString(int _a, int _b, int _c) {
        res="";
        a[1]=Node(_a,'a');
        a[2]=Node(_b,'b');
        a[3]=Node(_c,'c');
        sort(a+1,a+4);
        while(a[3].num)//a[3]保存的是数量最多的字母，这个条件意即字符还有剩
        {
            int l=res.length();
            if(l>=2 && res[l-1] == res[l-2]){//如果当前最后两个字母一样，就要特殊处理
                int ok=0;
                for(int i=3;i>=1;--i) if(a[i].num && a[i].ch!=res[l-1]){//当前字符还剩，并且不等于当前串末尾的字符
                    ok=1;add(i);break;
                }
                if(!ok) break;//无法再加入字符
            }
            else add(3);//否则直接往最后塞最多的字母
        }
        return res;
    }
};
```
