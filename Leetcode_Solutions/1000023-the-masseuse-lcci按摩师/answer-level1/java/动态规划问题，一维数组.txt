
动态规划函数为：
dp(i) = Math.max{ dp(i - 1), dp(i - 2) + nums[i], dp[i - 3] + nums[i] }

最多为前三个数，因为前四个数的话，第一个数和第三个数是可以相加的。
比如说 1 2 3 4 5， 是可以1 + 3 + 5的，因此这不是一次递归条件，所以到5点只能比较前四个数 2 3 4 5的位置。


```java
class Solution {
    public int massage(int[] nums) {
        if(nums.length == 0) return 0;
        int[]dp = new int[nums.length];
        int index = 0;
        for(int i : nums){
            if(index == 0) dp[index] = i;
            else if(index == 1) dp[index] = Math.max(dp[index - 1], i);
            else if(index == 2) dp[index] = Math.max(dp[index - 2] + i, dp[index - 1]);
            else{
                dp[index] = Math.max(dp[index - 1], dp[index - 2] + i);
                dp[index] = Math.max(dp[index], dp[index - 3] + i);
            }
            index++;
        }
        return dp[nums.length - 1];
    }
}
```
