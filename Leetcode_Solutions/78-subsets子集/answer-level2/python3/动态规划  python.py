### 解题思路
每次取出nums的第一个元素，并将其和其与上一次递归结果的组合项加入结果res中。

### 代码

```python
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.res=[]
        self.subsets_Rec(nums)
        self.res.append([])
        return self.res

    def subsets_Rec(self,nums):
        if nums==[]:
            return []
        fanhui=[[nums[0]]]+[[nums[0]]+x for x in self.subsets_Rec(nums[1:])]
        self.res+=fanhui
        return self.res
```