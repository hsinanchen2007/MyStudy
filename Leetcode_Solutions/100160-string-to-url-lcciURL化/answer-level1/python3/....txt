### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        return S[:length].replace(" ","%20")
```