### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        '''
        return list(set(range(1,len(nums)+1))-set(nums))
        '''

        '''
        s = set(nums)
        print(nums)
        return [i for i in range(1,len(nums)+1) if i not in s]
        '''
        '''
        return list(set(range(1,len(nums)+1)).difference(set(nums)))
        '''
        '''
        if nums is None: return None
        set1 = set(nums)
        set2 = set(range(1,len(nums)+1))
        return list(set2-set1)
        '''

        res=[]
        nums_set = set(nums)
        for i in range(1,len(nums)+1):
            if i not in nums_set:
                res.append(i)
        return res


```