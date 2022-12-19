### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if (n == 1)
            return 1;
        int first = 0;
        int second  =1;
        int total = 0;
        int mod = 1e9+7;
        for (int i = 2; i<= n; i++){
            total = (second+first)%mod;
            first = second;
            second = total;
        }
        return total;
    }
};
```