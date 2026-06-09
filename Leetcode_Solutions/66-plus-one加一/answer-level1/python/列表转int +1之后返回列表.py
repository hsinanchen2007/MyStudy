### 解题思路
先把列表转为int. +1 之后再用列表推导式转为列表.

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        strs = ''
        for i in digits:
            strs += str(i)
        nint = int(strs) + 1
        return [int(x) for x in str(nint)]

```