![捕获.PNG](https://pic.leetcode-cn.com/705055a0c5b75b884b086038d640e70e28d4d832f0f545299bac3d10f5766ce0-%E6%8D%95%E8%8E%B7.PNG)

迭代解决。

```
class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        else if(n==1)return 1;
        vector<int>res(n+1,0);
        res[0]=0;res[1]=1;
        for(int i=2;i<=n;++i){res[i]=res[i-1]+res[i-2];res[i]=res[i]%(1000000007);}
        return res[n];
    }
};
```

