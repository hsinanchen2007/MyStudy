![截屏2019-12-16下午2.29.04.png](https://pic.leetcode-cn.com/852b2fa4d0004aece75e7c2eece74b41ab17835e7b53b08c249e5b2d6a371a74-%E6%88%AA%E5%B1%8F2019-12-16%E4%B8%8B%E5%8D%882.29.04.png)
```
class Solution {
    public int subtractProductAndSum(int n) {
    int sum=0;int mup=1;
    while(n>0)
    {
        sum+=(n%10);mup*=(n%10);
        n=n/10;
    }
    return mup-sum;
    }
}
```