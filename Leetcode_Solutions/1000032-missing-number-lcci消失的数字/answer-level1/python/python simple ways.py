### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        '''
        length = sorted(nums)[-1]
        for i in range(0,length+1):
            if i not in nums:
                return i
        return length+1
        '''

        '''
        store = [0]*(len(nums)+1)
        for i in nums:
            store[i] = 1
        return store.index(0)
        '''

        res = 0
        for i in range(len(nums)):
            res^=i
            res^=nums[i]
        res^=len(nums)
        return res
```