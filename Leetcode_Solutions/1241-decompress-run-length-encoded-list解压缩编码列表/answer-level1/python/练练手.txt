### 解题思路
此处撰写解题思路
以两个数作为一个组合，用i记录组合数，然后一一对应

执行用时 :20 ms, 在所有 Python 提交中击败了99.38%的用户
内存消耗 :12.1 MB, 在所有 Python 提交中击败了100.00%的用户
### 代码

```python
class Solution(object):
    def decompressRLElist(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        lens=len(nums)
        i=lens/2
        ans=[]
        for j in range(1,i+1):
            for k in range(nums[2*j-2]):
                ans.append(nums[2*j-1])
            k=0
        return ans
```