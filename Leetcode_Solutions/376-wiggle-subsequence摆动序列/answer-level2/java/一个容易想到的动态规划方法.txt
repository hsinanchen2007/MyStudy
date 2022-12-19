# 思路
与上一道题类似，区别在于，摆动序列的定义，以[1,7,4,9,2,5]为例，这就是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。
我们可以同样定义dp[i]为代表取i为结尾能取到的最长摆动序列长度。我们需要注意以下几点。
（1）题中有条件少于两个元素的序列也是摆动序列，因此只有一个元素的话也是摆动序列。
（2）如果取当前i作为摆动序列的尾部，它有两种可能：
**1.比nums[j]大，这样由nums[j]到nums[i]组成升序，如果可以组成摆动序列的话，前面的值和nums[j]就需要是降序关系
2.比nums[j]小，这样由nums[j]到nums[i]组成降序，如果可以组成摆动序列的话，前面的值和nums[j]就需要是升序关系**
由此可知，我们不能只定义一维数组，我们需要定义二维数组，状态方程如下：
```java
		想取dp[i][0]代表以i为结尾且i-1到i为升,dp[i][1]代表以i为结尾且i-1到i为降
        当前nums[i]大于nums[j]，则可以取从j到i上升，因此可以取dp[j][i]+1，因此之前的值与j需要是下降关系所以取的是dp[j][1]
        dp[i][0] = Math.max(if(nums[i]>nums[j])dp[j][1]+1),j:[0,i-1]
        与上面同理
        dp[i][1] = Math.max(if(nums[i]<nums[j])dp[j][0]+1),j:[0,i-1]
```
最后在遍历dp数组找到最大值。

# 代码

```java
class Solution {
    public int wiggleMaxLength(int[] nums) {
        /*动态规划
        dp[i]代表取i以结尾能取到的最长摆动序列的长度
        想取dp[i][0]代表以i为结尾且i-1到i为升,dp[i][1]代表以i为结尾且i-1到i为降
        当前nums[i]大于nums[j]，则可以取从j到i上升，因此可以取dp[j][i]+1，因为j需要与之前的值是下降关系所以取的是dp[j][1]
        dp[i][0] = Math.max(if(nums[i]>nums[j])dp[j][1]+1),j:[0,i-1]
        与上面同理
        dp[i][1] = Math.max(if(nums[i]<nums[j])dp[j][0]+1),j:[0,i-1]
        */
        if(nums==null||nums.length==0)
            return 0;
        if(nums.length<2)
            return 1;
        int[][]dp = new int[nums.length][2];
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i=1;i<nums.length;i++)
        {
            dp[i][0] = 1;
            dp[i][1] = 1;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                    dp[i][0] = Math.max(dp[i][0],dp[j][1]+1);
                else if(nums[i]<nums[j])
                    dp[i][1] = Math.max(dp[i][1],dp[j][0]+1);
            }   
        }
        int max =1;
        for(int i=0;i<nums.length;i++)
        {
            int nowmax = Math.max(dp[i][0],dp[i][1]);
            max = Math.max(max,nowmax);
        }
        return max;
    }
}
```
