### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        '''
        nums = list(set(nums))
        l = len(nums)
        if l==1:
            return nums[0]
        if l==2:
            return max(nums)
        nums.sort()
        return nums[l-3]
        '''

        '''
        s = set(nums)
        if len(s)<3:
            return max(s)
        s.remove(max(s))
        s.remove(max(s))
        return max(s)
        '''

        '''
        nums=set(nums)
        #nums={*nums}
        #nums=[*{*nums}]
        if len(nums)<3:
            return max(nums)
        return sorted(nums,reverse=True)[2]
        '''

        nums=[*{*nums}]
        if len(nums)<3: return max(nums)
        return heapq.nlargest(3, nums)[2]
```