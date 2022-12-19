### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        '''
        dict={}
        for i,num in enumerate(nums):
            dict[num] = i
            if dict.get(num) is not None:
                if i-dict[num]<=k:
                    return True
                else:
                    dict[num]=i
            else:
                dict[num]=i
        return False
        '''
        
        '''
        dict={}
        if len(set(nums))==len(nums): return False
        for i,num in enumerate(nums):
            if num in dict and i-dict[num]<=k:
                return True
            dict[num]=i
        return False
        '''

        '''
        if len(set(nums))==len(nums): return False
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i]==nums[j] and abs(i-j)<=k:
                    return True
        return False
        '''

        dict = collections.defaultdict(list)
        for i, num in enumerate(nums):
            dict[num].append(i)
        for val in dict.values():
            for i in range(len(val)-1):
                if val[i+1]-val[i]<=k:
                    return True
        return False

```