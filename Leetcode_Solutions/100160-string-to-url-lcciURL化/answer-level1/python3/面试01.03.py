### 解题思路
去字符串真实长度后再进行替换

### 代码

```python3
class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        # return "%20".join(S[:length].split(" "))
        return S[:length].replace(" ","%20")
```