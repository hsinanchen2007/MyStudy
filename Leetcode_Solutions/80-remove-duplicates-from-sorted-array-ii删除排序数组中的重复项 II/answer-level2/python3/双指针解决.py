### 解题思路
此处撰写解题思路
用两个指针index表示当前符合条件数组的长度，cnt表示当值值得统计数，如果当前值和之前的值不一样的则将
cnt更新到1，如果当前值和前一位的值相等，如果这个值当前的数已将达到2那么跳过，否则的话将该值前提 同时
cnt +=1
### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return len(nums)
        index = 1
        cnt =1 
        for i in range(1,len(nums)):
            if nums[i] == nums[i-1] and cnt <2:
                nums[index] = nums[i]
                index +=1
                cnt +=1
            elif nums[i] != nums[i -1]:
                nums[index] = nums[i]
                index += 1
                cnt = 1
            else:
                pass
        return index    
```