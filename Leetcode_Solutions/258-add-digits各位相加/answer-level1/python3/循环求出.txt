### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def addDigits(self, num: int) -> int:
        while num >= 10:
            a = list(str(num))
            num = 0
            for i in a:
                num += int(i)
        return num
```