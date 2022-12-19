### 解题思路
这一题我记得之前做过。然后用分治的思想做出来了，然后测试了几个案例发现无误之后提交发现超时了。
然后我看了一下标签，发现这道题是动态规划。然后想了一下之前做过一道用1 2 5凑100的题也是可以用这两种方法做的。
然后尝试用动态规划解这个题。
这里不解释分治的思想了。

动态规划的思想起始也是一个搜索，使用之前搜索到的结果就是关键点。也是原问题可以分解成等价的子问题解决。
首先应该明确：你有了1，2，5去凑10的话。你可以有1 + dp[9] / 1 + dp[8] / 1 + dp[5]。这三种解。
然后继续将这三种解进行继续划分。如果i - nums[i] < 0 就会返回；

当我把dp[0]初始化=1的时候，你就可以去遍历，然后将满足条件的加起来了。这里的dp[0] 起始就是1 = 1; 2 = 2; 5 = 5的情况。

### 代码

```java
class Solution {
    // //可以回顾一下组合总和这几道题目
    // List<List<Integer>> lists = new ArrayList<>();

    // public void function(List<Integer> list, int[] nums, int target, int start){
    //     if(target < 0)
    //         return;
    //     if(target == 0){
    //         lists.add(new ArrayList(list));
    //         return;
    //     }
    //     else{
    //         for(int i = start; i < nums.length; i++){
    //             list.add(nums[i]);
    //             //如果不要求重复的话，下面的start置为i即可。
    //             function(list, nums, target-nums[i], 0);
    //             list.remove(list.size()-1);
    //         }
    //     }
    // }

    public int combinationSum4(int[] nums, int target) {
        // List<Integer> list = new ArrayList<>();
        // function(list, nums, target, 0);
        // return lists.size();

        if(nums.length == 0) 
            return 0;

        int[] dp = new int[target+1];
        dp[0] = 1;

        for(int i = 1; i <= target; i++){
            for(int j = 0; j < nums.length; j++){
                if(i - nums[j] >= 0){
                    dp[i] = dp[i] + dp[i-nums[j]];
                }
            }
        }

        return dp[target];
    }
}
```