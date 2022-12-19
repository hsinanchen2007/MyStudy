### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        if(n == 0)  return 1;
        if(n == 1)  return 1;
        if(n == 2)  return 2;
        int fib1 = 1 , fib2 = 2;
        for(int i = 3 ; i <= n ; i ++) {
            fib2 = (fib1 + fib2) % 1000000007;
            fib1 = (fib2 - fib1) % 1000000007;
        }
        return (fib2 + 1000000007) % 1000000007;
    }
};
```