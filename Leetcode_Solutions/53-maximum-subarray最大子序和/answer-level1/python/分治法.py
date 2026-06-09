### 解题思路
写一种分治法玩玩，比直接遍历有趣

### 代码

```python
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if(len(nums) == 1):
            return nums[0]
        cut = len(nums) // 2
        leftSum = self.maxSubArray(nums[:cut])
        rightSum = self.maxSubArray(nums[cut:])
        
        maxL = 0
        maxR = 0
        leftSumTemp = 0
        rightSumTemp = 0
        for i in range(cut -1, -1, -1):
            leftSumTemp += nums[i]
            maxL = max(maxL, leftSumTemp)
            
        for i in range(cut + 1, len(nums), 1):
            rightSumTemp += nums[i]
            maxR = max(maxR, rightSumTemp)
            
        return max(leftSum, maxL + nums[cut] + maxR, rightSum)
```

```java
class Solution {
    public int maxSubArray(int[] nums) {
        return maxSubArrayIndex(nums, 0, nums.length - 1);
    }
    
    public int maxSubArrayIndex(int[] nums, int left, int right) {
        if(right == left){
            return nums[left];
        }
        int cut = (left + right) / 2;

        int leftSum = maxSubArrayIndex(nums, left, cut);
        int rightSum = maxSubArrayIndex(nums, cut + 1, right);

        int maxL = 0;
        int maxR = 0;
        int leftSumTemp = 0;
        int rightSumTemp = 0;

        for (int i = cut - 1; i >= 0; i--) {
            leftSumTemp += nums[i];
            maxL = Math.max(maxL, leftSumTemp);
        }

        for (int i = cut + 1; i < nums.length; i++) {
            rightSumTemp += nums[i];
            maxR = Math.max(maxR, rightSumTemp);
        }

        return Math.max(maxL + nums[cut] + maxR, Math.max(leftSum, rightSum));
    }
}
```
