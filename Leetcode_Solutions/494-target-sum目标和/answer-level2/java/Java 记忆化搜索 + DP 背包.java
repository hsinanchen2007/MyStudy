虽然有点慢(274ms，击败46.2%)，没有其它方法优，但是这是最直接的思路，也就是暴力递归，再加上记忆化操作，也能AC。
别管他黑猫白猫，能抓老鼠的就是好喵。

思路就是 画个树形图呀，这类递归就是个树形问题。对于nums数组的每一个数字，要么是`+`，要是是`-`, 所以递归，树的深度是nums数组的长度。是一棵满二叉树。
示例：
```
输入: nums: [1, 1, 1], S: 1
输出: 3
```

关于设置为-S,是因为 S 等于nums数组加上正负符号后的和，记为sum,S==sum,移项，-S+sum == 0, 递归终止条件是用完nums数组中每个数字，满足条件的为最终值等于0的。（讲的好乱....）

![image.png](https://pic.leetcode-cn.com/5fb96e7ecfdfb440dbcc9f0e65deb52b78adcfefba53714aa618ba90874183fb-image.png)

# 记忆化搜索

```java
import javafx.util.Pair;
class Solution {
    HashMap<Pair<Integer,Integer>, Integer> memo;
    public int findTargetSumWays(int[] nums, int S) {
        memo = new HashMap<>();
        return helper(nums, -S, 0);
    }
    private int helper(int[] nums, int S, int index){
        if (index==nums.length){
            if (S==0)   return 1;
            return 0;
        }
        if (memo.containsKey(new Pair<>(S, index)))
            return memo.get(new Pair<>(S, index));
        int res = 0;
        int left = helper(nums, S-nums[index], index+1);
        int right = helper(nums, S+nums[index], index+1);
        res = res + left + right;
        memo.put(new Pair<>(S, index), res);
        return res;
    } 
}
```


# 动态规划
01背包问题
动态规划这里dp的取值范围可能为负数，所以难点在于需要将区间平移一下，[-sum,sum] ==> [0,2*sum]
```java
//dp[i][j]表示前i个数和为j的方法数为dp[i][j]
//dp[i][j]=dp[i-1][i-nums[i-1]] + dp[i-1][i+nums[i-1]];
public int findTargetSumWays(int[] nums, int S) {

    int sum = 0;
    for(int n: nums){
        sum += n;
    }
    if (S < -sum || S > sum)    return 0;
    int[][] dp = new int[nums.length + 1][ 2 * sum + 1];

    dp[0][0+sum]=1; // 表示0个数字，合为0的方法数为1, 0+sum 就代表0, 0代表-sum
    for (int i = 1;i<=nums.length;i++){
        for (int j = 0;j<2*sum+1;j++){
            if(j + nums[i - 1] < 2  * sum + 1) dp[i][j] += dp[i - 1][j + nums[i - 1]];
            if(j - nums[i - 1] >= 0) dp[i][j] += dp[i - 1][j - nums[i - 1]];
        }
    }
    return dp[nums.length][sum+S];
}
```
