### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        '''
        dict={}
        for i in nums:
            dict[i]=dict.get(i,0)+1
            if dict[i]>1:
                return True
        return False
        '''

        '''
        return len(nums)!=len(set(nums))
        '''

        '''
        nums.sort()
        for i in range(1,len(nums)):
            if nums[i-1]==nums[i]:
                return True
        return False
        '''

        '''
        s = len(collections.Counter(nums))
        if s<len(nums):
            return True
        return False
        '''

        visited = set()
        for num in nums:
            if num in visited:
                return True
            visited.add(num)
        return False
```