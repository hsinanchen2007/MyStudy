### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    long long waysToStep(int n) {
        //f(n) = f(n-1) + f(n-2) + f(n-3)
        if(n == 1)return 1;
        if(n == 2)return 2;
        if(n == 3)return 4;
        long long c1 = 1, c2 = 2, c3 = 4;
        int p = 1000000007;
        for(int k = 4; k <= n; ++k)
        {
            long long c = (c1%p + c2%p + c3%p) % p;
            c1 = c2%p;
            c2 = c3%p;
            c3 = c;
        }
        return c3;
    }
};
```