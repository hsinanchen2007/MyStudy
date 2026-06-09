### 解题思路
设置max保存最大子序列和，设定初始值为第一个元素
循环判定：若sum+nums[i]>max max=sum+nums[i]
如果sum小于0，则sum与其后元素 的和必然小于此元素，令sum=0
### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum=0
        max=nums[0]
        for i in range(len(nums)):
            sum+=nums[i]
            if sum>max:
                max=sum
            if sum<0:
                sum=0         
        return max
```