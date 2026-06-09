### 解题思路
分两种情况，偷第一个房子和不偷第一个房子

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)==1:
            return nums[0]
        def my_rob(num):
            pre,cur=0,0
            for n in num:
                pre,cur=cur,max(n+pre,cur)
            return cur
        return max(my_rob(nums[:-1]),my_rob(nums[1:])) 

        
```