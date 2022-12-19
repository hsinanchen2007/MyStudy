### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        s,n,mm = 0,0,nums[0]
        for i in nums:
            s += i  # 加上当前元素
            n = max(s,i)  # 如果前面的和还没有当前这个值大，那么
            mm = max(mm,n)  # mm是前面多个元素的最大可能的和
            s = n 
        return mm 

```