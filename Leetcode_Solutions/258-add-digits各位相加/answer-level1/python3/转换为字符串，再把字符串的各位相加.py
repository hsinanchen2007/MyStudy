### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def addDigits(self, num: int) -> int:
        while num>=10:
            s = str(num)
            length = len(s)
            num = 0
            for i in range(0, length, 1):
                num += int(s[i])

        return num

```