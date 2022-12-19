注意特殊情况就可以辽
```
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if(a>b)swap(a,b);
        if(b>c)swap(b,c);
        if(a>b)swap(a,b);
        int mi=(c-b>1?1:0)+(b-a>1?1:0);
        int ma=c-a-2;
        if(c-b==2||b-a==2)mi=1;
        return {mi,ma};
    }
};
```
