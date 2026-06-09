### 解题思路
方法一：贪心算法。假设每一步都能得到目前为止的最佳方案，当遍历完整个数组时，也一定能够得到最佳方案。时间复杂度：O(n),空间复杂度：O(1)。
### 代码
```java
class Solution {
    public int maxSubArray(int[] nums) {
        //贪心算法:每一步都选择最佳方案，最终得到全局最佳方案
        int currSum = nums[0], maxSum = nums[0];

        for(int i = 1; i < nums.length; i++){
            currSum = Math.max(nums[i], currSum + nums[i]);
            maxSum = Math.max(maxSum, currSum); //每一步都是最佳方案
        }

        return maxSum;
    }
}
```

方法二：动态规划DP。
### 代码
```java
class Solution {
    public int maxSubArray(int[] nums) {
        //动态规划（资源推荐：bilibili的大雪菜的闫氏DP分析法）
        int maxSum = nums[0];

        for(int i = 1; i < nums.length; i++){
            if(nums[i - 1] > 0){
                //动态规划方程
                nums[i] += nums[i - 1];
            }
            maxSum = Math.max(nums[i],maxSum);
        }

        return maxSum;
    }
}
```