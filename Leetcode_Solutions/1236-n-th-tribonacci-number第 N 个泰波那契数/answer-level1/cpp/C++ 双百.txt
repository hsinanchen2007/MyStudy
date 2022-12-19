思路跟斐波那契数列一样；保存中间状态即可
```
int tribonacci(int n) {
        int t0=0,t1=1,t2=1,res=0;
        if(n==0)
            return t0;
        if(n==1 ||n==2)
            return 1;
        for(int i=3;i<=n;i++){
            res=t0+t1+t2;
            t0=t1;
            t1=t2;
            t2=res;
        }
        return res;
    }
```
