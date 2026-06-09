### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
/*    int fib(int N) {                   //递归方法 16ms
        if(N == 0 || N == 1){
            return N;
        }
        return fib(N-1) + fib(N-2);
    }*/
    int fib(int N) {                    // 动态规划 0ms
        if(N == 1 || N == 0){
            return N;
        }
        int dp0 = 0;
        int dp1 = 1;
        for(int i = 2; i <= N; i++){
            int cur = dp0;
            dp0 = dp1;
            dp1 = dp0 + cur;
        }
        return dp1;
    }
};
```