提供一种hash思路：
对于一个32位整型数缩放其范围其最大值不会超过 9999999999,
那么对于这个数做一次"快乐的"运算值也不过是810,
那么明显800大的数组足够存下所有情况，实现了1次查询便知道是否有循环节。
```
class Solution {
public:
    int ans[800] = {0};
    int getsum(int n)
    {
        int tmp = 0;
        int ans = 0;
        while(n!=0)
        {
            tmp = n % 10;
            ans += tmp * tmp;
            n = n / 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        
        n = getsum(n);
        if(n == 1) return true;
        while(ans[n] != 1)
        {
            ans[n] = 1;
            n = getsum(n);
            if(n == 1)
                return true;
        } 
        return false;
    }
};
```
大概就是这个思路。