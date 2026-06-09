### 解题思路
一、排序，占用一个辅助列表
二、设置两个指针，分别对应第一个和最后一个**不在顺序位置上**的值的下标
三、返回last-first+1

### 代码

```python3
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        nums_sorted=sorted(nums)
        first=len(nums)-1
        last=0
        if len(nums)==1 or nums_sorted==nums:
            return 0
        for i in range(len(nums)):
            if nums[i]!=nums_sorted[i]:
                first=i
                break
        for j in range(len(nums)):
            if nums[j]!=nums_sorted[j]:
                last=j
        
        return last-first+1
        



```