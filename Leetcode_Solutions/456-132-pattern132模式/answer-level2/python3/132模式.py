### 解题思路
**思路：**
求一个list中是否有132模式。利用一个栈，从后往前遍历数组，再设置一个second变量。栈中记录的是当前遍历到的最大值，而second则用来记录目前第二大的数。只要目前遍历的数，小于栈顶的最大值和second，这时候就刚好满足132模式。

### 代码

```python3
class Solution:
    def find132pattern(self, nums: List[int]) -> bool: 
        if len(nums) <= 2:
            return False
        stack = []
        second = float('-inf')
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] < second:
                return True
            while stack and nums[i] > stack[-1]:
                second = stack.pop()
            stack.append(nums[i])
        return False
```