### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        int a = 1, b = 1;   // base case
        int res;
        for(int i = 3; i <= n; ++i)
        {
            // 要在for里边取模，不能在return的时候取模，那样的话a和b也会溢出的
            res = (a + b) % 1000000007;
            a = b;
            b = res;
        }
        return res ;

    }
};
```