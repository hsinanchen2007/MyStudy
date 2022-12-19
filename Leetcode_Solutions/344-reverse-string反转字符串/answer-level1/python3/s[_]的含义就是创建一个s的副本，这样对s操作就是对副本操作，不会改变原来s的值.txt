### 解题思路
s[:]的含义就是创建一个s的副本，这样对s操作就是对副本操作，不会改变原来s的值

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        s[:]=s[::-1]
```