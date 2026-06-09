```
class Solution {
public:
    int waysToStep(int n) {
        long long int a=1,b=2,c=4,tmp;
        if(n==1) return a;
        if(n==2) return b;
        if(n==3) return c;
        for(int i=4;i<=n;i++){
            tmp=(a+b+c)%1000000007;
            a=b;
            b=c;
            c=tmp;
        }
        return tmp;

    }
};
```
