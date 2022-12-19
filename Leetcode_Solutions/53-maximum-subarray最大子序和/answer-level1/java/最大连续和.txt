### 第一种方法：分治法

分治法的策略一般分为三步：
- 定义基本情况
- 将大问题不断分解为小问题，递归的解决
- 合并所有情况并获得解

针对于该题，如果将整个数组分为左右两部分，该题可以把需要求解的目标序列（最大和序列）分为三种基本情况
- 目标序列都在左半边
- 目标序列都在右半边
- 目标序列左右横跨

所以可以利用分治法递归的解决，如图（引用）：
![最大连续和.jfif](https://pic.leetcode-cn.com/055541ad2dc5cf54f83f3dea5b34bf96741d3894a29aeaeadb5914c4dc24f4c1-%E6%9C%80%E5%A4%A7%E8%BF%9E%E7%BB%AD%E5%92%8C.jfif)


### 分治法代码

```java
class Solution {
    //第一种方法，分治法
    public int maxSubArray(int[] nums) {
        if(nums == null || nums.length == 0)
            return 0;

        return helper(0,nums.length-1,nums);
    }

    public int helper(int left,int right,int nums[]){

        if(left > right)
            return Integer.MIN_VALUE;

        int mid = (left+right) >>> 1;
        
        //左边最大
        int leftMaxSum = helper(left,mid-1,nums);
        //右边最大
        int rightMaxSum = helper(mid+1,right,nums);

        //计算横跨左右的最大数值

        //横跨的左边部分
        int currentSum = 0,spanLeftMax=0;
        for(int i = mid-1; i >= left;i--){
            currentSum += nums[i];
            spanLeftMax = Math.max(spanLeftMax,currentSum);
        }

        //横跨的右边部分
        currentSum=0;
        int spanRightMax = 0;

        for(int i = mid+1; i <=right; i++){
            currentSum += nums[i];
            spanRightMax = Math.max(spanRightMax,currentSum);
        }

        return Math.max(spanRightMax+spanLeftMax+nums[mid],
                        Math.max(leftMaxSum,rightMaxSum));

    }
}
```

### 第二种方法：动态规划法

假设dp[i]为第i次的最优解，那么第i+1次的最优解为

`dp[i+1] = Math.max(nums[i+1],dp[i]+nums[i+1]);`

即向后加上一个元素，在前一个最优解和加上这个元素的最优解取最大值

初始化：`dp[0] = nums[0]`

### 动态规划代码

```java
class Solution {
    //第二种方法，分治法
    public int maxSubArray(int[] nums) {
        if(nums == null || nums.length == 0)
            return 0;

        int currentSum = nums[0],maxSum = nums[0];

        for(int i = 1; i < nums.length; i++){
            currentSum = Math.max(nums[i],currentSum+nums[i]);
            maxSum = Math.max(currentSum,maxSum);
        }

        return maxSum;
    }
}
```