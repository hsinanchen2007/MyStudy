### 解题思路
递归发现会超时，也不需要数组几个变量定义就够了，假设res这个数前两个数是zero和one，每次res递增时，zero，one往后移动，新zero等于旧one，新one等于旧res.

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        if(n == 0){return 0;}
        if(n==1){return 1;}
        int zero = 0;int one = 1;int res;
        for(int i = 2;i<=n;i++)
        {
            res = (zero+one)%1000000007;
            zero = one;
            one = res;
        }
        return res;
    }
};
```