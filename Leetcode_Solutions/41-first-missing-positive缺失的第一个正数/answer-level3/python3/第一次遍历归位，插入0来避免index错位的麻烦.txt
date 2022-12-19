### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if not nums or 0 not in nums: nums.append(0) #此处插入一个可能不会在list中出现的0，用来使所有值对齐到位置
        for i in range(len(nums)):
            if nums[i]==i:
                continue
            while nums[i]>=0 and nums[i]<len(nums) and nums[i]!=i and nums[i]!=nums[nums[i]]:
                #边界条件，0~N归位，nums[i]!=nums[nums[i]]避免循环
                tmp = nums[i]
                nums[i] = nums[tmp]
                nums[tmp] = tmp

        #再遍历一次找出最小的正数，因此从1位置开始找（因为我们插入了0所以0位置永远对齐）
        for j in range(1, len(nums)):
            if nums[j]!=j:
                return j
        #找不到返回最大正数
        return len(nums)
        
```