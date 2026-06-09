### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        n = len(nums)
        
        def backtrack(i, list_one):
            #if n>=len(list_one):  #and list_one not in res_list :
            res.append(list_one[:])
            
            for j in range(i, n):
                list_one.append(nums[j])
                backtrack(j + 1,list_one )
                list_one.pop()
        res = []
        list_one = []
        backtrack(0, list_one)
        return res  

 
```