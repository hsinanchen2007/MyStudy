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
        def dfs(ans,nums,list,index):
            if(index==len(nums)):
                ans.append(list[:])
                return
            dfs(ans,nums,list,index+1)
            list.append(nums[index])
            dfs(ans,nums,list,index+1)
            list.pop()
        ans=[]
        if nums==None:
            return ans
        dfs(ans,nums,[],0)
        return ans
            
```