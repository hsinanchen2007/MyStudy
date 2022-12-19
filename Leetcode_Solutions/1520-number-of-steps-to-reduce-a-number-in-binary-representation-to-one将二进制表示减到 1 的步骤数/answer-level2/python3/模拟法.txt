### 解题思路
直接二进制转十进制太赖皮了，再写一个模拟法的
末尾为0，计数加一，判断前一位
末尾为1：
       很多个末尾为1，一次性模拟加一后的全部移位操作，直到计数小于0（或达到另一个0）
       将小于零的计数变为自然数
### 代码

```python3
class Solution:
    def numSteps(self, s: str) -> int:
        time = 0
        idx = len(s) - 1
        while(idx >= 0):
            print(idx, time)
            if s[idx] == '0':
                idx -= 1
                time += 1
            else:            
                if idx == 0: return time
                while(idx >= 0 and s[idx] == '1'):
                    idx -= 1
                    time += 1
                idx = max(0, idx)
                s = s[:idx] + '1' + s[idx+1:]
                time += 1
                
```