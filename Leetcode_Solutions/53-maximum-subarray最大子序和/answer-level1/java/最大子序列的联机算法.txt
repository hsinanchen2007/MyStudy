### 解题思路
时间复杂度为O(N).
### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        //因为（子数组最少包含一个元素），所以maxSum的初值不能为0.
        int thisSum=0,maxSum=nums[0];
        for(int i:nums)
        {
            thisSum=thisSum+i;
            maxSum=Math.max(thisSum,maxSum);    
            if(thisSum<0)
               thisSum=0;         
        }
        return maxSum;

    }
}
```