### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: list) -> int:
        stack = []
        result = []
        for k,v in enumerate(nums):
            if v not in stack:
                stack.append(v)
            else:
                result.append(k)
        for t,i in enumerate(result):
            print(nums.pop(i-t))
```