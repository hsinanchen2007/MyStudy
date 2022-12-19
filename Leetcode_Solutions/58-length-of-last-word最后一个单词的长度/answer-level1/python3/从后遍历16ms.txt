### 解题思路
去末尾空格
判断字符串有没有空隔，没有则返回原长度
### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.rstrip()
        if s.count(' ') == 0:
            return len(s)
        x = 0
        while True:
            if s[-(x+1)] == ' ':
                return x
            x += 1
            
```