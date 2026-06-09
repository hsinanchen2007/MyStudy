### 解题思路
1.使用暴力法递归求所有的方法，并把记录存入memo数组中避免冗余计算。

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int* memo = new int[n + 1];
        return climb_Stairs(0,n,memo);
    }
    int climb_Stairs(int i, int n, int memo[]){
        if(i > n){
            return 0;
        }
        
        if(i == n){
            return 1;
        }
        
        if(memo[i] > 0){
            return memo[i];
        }
        memo[i] = climb_Stairs(i + 1,n,memo) + climb_Stairs(i + 2,n,memo);
        return memo[i];
    }
};
```