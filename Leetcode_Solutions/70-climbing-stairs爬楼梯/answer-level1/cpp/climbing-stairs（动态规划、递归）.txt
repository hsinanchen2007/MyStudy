### 代码

```cpp
//动态规划
class Solution {
public:
int climbStairs(int n) {
    if(n==0||n==1) return 1;
    vector<int> memo(n+1,1);
    for(int i=2;i<=n;i++) 
        memo[i]=memo[i-1]+memo[i-2];
    return memo[n];
}
};
//递归优化：记忆化搜索
class Solution {
private:
    vector<int> memo;
    int helper(int n) {
        if(n==0||n==1) return 1;
        if(memo[n]==-1) 
            memo[n]=helper(n-1)+helper(n-2);
    return memo[n];
    }
public:
int climbStairs(int n) {
    memo =vector<int>(n+1,-1);
    return helper(n);
}
};
```