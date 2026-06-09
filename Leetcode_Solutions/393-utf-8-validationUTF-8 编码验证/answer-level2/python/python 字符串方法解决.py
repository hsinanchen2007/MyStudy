## 思路:

模拟过程即可

思路一：字符串

```python
class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        if not data: return False
        data = [bin(d)[2:].rjust(8, "0") for d in data]
        # print(data)
        cnt = 0
        for d in data:
            if cnt == 0:
                if d.startswith("0"): continue
                elif d.startswith("110"): cnt = 1
                elif d.startswith("1110"): cnt = 2
                elif d.startswith("11110"): cnt = 3
                else:
                    return False
            else:
                if not d.startswith("10"): return False
                cnt -= 1
        return cnt == 0
```

思路二：位运算

```python
class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        if not data: return False
        cnt = 0
        for d in data:
            if cnt == 0:
                if d >> 5 == 0b110: cnt = 1
                elif d >> 4 == 0b1110: cnt = 2
                elif d >> 3 == 0b11110: cnt = 3
                elif d >> 7 != 0:
                    return False
            else:
                if d >> 6 != 0b10: return False
                cnt -= 1
        return cnt == 0
        
```