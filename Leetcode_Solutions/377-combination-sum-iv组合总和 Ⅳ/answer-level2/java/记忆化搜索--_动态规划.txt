记忆化搜索，就是回溯过程中记忆重叠子问题的答案。

对于例子
nums = [1, 2, 3]
target = 4
```
        4
     /  |  \    分别-1，-2，-3
    3   2   1
  / | \         再分别-1，-2，-3知道等于0为止，这些减数的路径就是一个符合题意的组合。
 2  1  0 ....
```
即状态转移方程为f(4) = f(3) + f(2) + f(1);

# 记忆化搜索
```java
int[] memo;
public int combinationSum4(int[] nums, int target) {
    memo = new int[target+1];
    Arrays.fill(memo, -1);
    return backtracking(target,nums);
}
private int backtracking(int target, final int[] candidates) {
    if (target == 0) {
        return 1;
    }
    if (memo[target]!=-1)
        return memo[target];
    int res = 0;
    for (int i = 0; i < candidates.length; i++) {
        if (candidates[i] <= target) {
            res += backtracking(target - candidates[i], candidates);
        }
    }
    memo[target] = res;
    return res;
}
```

# DP
```java
public int combinationSum4(int[] nums, int target) {
    int[] dp = new int[target+1];
    dp[0]=0;

    //初始化，表示dp[nums[i]] = 1; 或者不用这步设置，把dp[0]=1就可以。
    for (int i = 0;i<nums.length;i++){
        if (nums[i]<=target)
            dp[nums[i]] = 1;
    }
    for (int i = 1;i<=target;i++){
        for (int j = 0;j<nums.length;j++){
            if (i<nums[j])  continue;
            dp[i] = dp[i] + dp[i-nums[j]];
        }
        // System.out.println("dp["+ i +"]= " + dp[i]);
    }
    return dp[target];
}
```


