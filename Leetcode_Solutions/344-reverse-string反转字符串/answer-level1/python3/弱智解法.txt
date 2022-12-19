### 解题思路
遍历字符串 每次把最后一位插入到当前遍历的位置. len(s)-1 是为了防止把第一次循环插入在0位的字符pop.

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        for i in range(len(s)-1):
            s.insert(i, s.pop(-1))
```