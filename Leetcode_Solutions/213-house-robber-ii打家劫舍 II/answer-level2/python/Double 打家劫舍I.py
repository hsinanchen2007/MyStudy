### 解题思路
不要让nums[0] 和 nums[-1] 有连起来的可能
nums[0]和nums[1]必然只能选1个。所以做了两次O(N)遍历。

### 代码
```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)==1:return nums[0]
        a,b,c,d = 0,0,0,0
        for num in nums[:-1]:
            a,b = b,max(a+num, b)
        for num in nums[1:]:
            c,d = d,max(c+num,d)
        return max(d,b)
```