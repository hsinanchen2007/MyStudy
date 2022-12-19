### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        n = len(nums)
        nums.sort()
        def backtrack(i, list_one):
            res.append(list_one[:])           
            for j in range(i, n):
                if j > i and nums[j] == nums[j-1]:continue
                list_one.append(nums[j])
                backtrack(j + 1,list_one )
                list_one.pop()
        res = []
        list_one = []
        backtrack(0, list_one)
        return res  
```