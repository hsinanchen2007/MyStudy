### 解题思路
思路待整理

### 代码

```python3
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        if len(nums) <= 1:
            return True

        descCount=0
        pre = 0
        for i in range(1,len(nums)):
            if nums[pre] > nums[i]: # 连续两个数相比较，前一个大于后一个，已经是逆序
                descCount += 1
                if i == 1:  # 如果是最开始的nums[0] > nums [1]，则pre往后移
                    pre = 1
                elif nums[i] >= nums[i-2]: # 中间比两边大，中间指的是 nums[pre]
                    pre = i
            else:
                pre = i
        return True if descCount <= 1 else False


```