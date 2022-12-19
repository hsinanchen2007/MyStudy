### 解题思路
除数和商来用于判断，思路简单，但是实现真的费时间，，，语言基础掌握的不好

### 代码

```python3
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        len_s = len(s)
        yushu = len_s % (2*k)
        shang = int(len_s/(2*k))
        string = ""
        for i in range(shang):
            zen = i*2*k
            string += s[k-1+zen:zen:-1]+s[zen]+s[k+zen:2*k+zen]

        if 0 < yushu < k:
            string += s[:shang*2*k:-1] +s[shang*2*k]
        elif k <= yushu < 2*k:
            string += s[shang*2*k-1+k:shang*2*k:-1]+s[shang*2*k]+s[shang*2*k+k:]
        return string
```