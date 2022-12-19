### 解题思路


### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        long int a1 = 0, a2 = 1, res, i;
        if(n <= 1)
        {
            return n;
        }
        for(i = 0; i < n - 1; ++i)
        {
            res = (a1 + a2) % 1000000007;
            swap(a1, a2);
            a2 = res;
        }
        return res;
    }
};
```