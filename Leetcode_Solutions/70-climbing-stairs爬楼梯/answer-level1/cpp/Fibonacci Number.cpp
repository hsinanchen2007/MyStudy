### 解题思路
常规 Fibonacci Number 

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int fn_2 = 1, fn_1 = 2;
        if(n==1) return 1;
        if(n==2) return 2;
        int res = 0;
        for(int i = 3; i<=n ; ++i){
            res = fn_2 + fn_1;
            fn_2 = fn_1;
            fn_1 = res;
        }
        return res;
    }
};
```