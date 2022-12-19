### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        if n==1:
            return nums[0]
        # 定义 头间房抢 最后间房不抢，或者 头间房不强，尾间房抢
        def helper(nums):
            m=len(nums)
            pre1=0
            pre2=0
            for i in range(m):
                cur= max(nums[i]+pre1,pre2)
                pre1=pre2
                pre2=cur
            return pre2
        # 两种情况：0-n-2  和 1-n-1
        return max(helper(nums[:n-1]),helper(nums[1:n]))
    
```