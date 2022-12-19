### 解题思路
直接for循环遍历得到的结果，如果是空格拼接%20，不是空格直接拼接。

### 代码

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
        result = ''
        for i in s:
            if i == ' ':
                result += '%20'
            else:
                result += i
        return result
```