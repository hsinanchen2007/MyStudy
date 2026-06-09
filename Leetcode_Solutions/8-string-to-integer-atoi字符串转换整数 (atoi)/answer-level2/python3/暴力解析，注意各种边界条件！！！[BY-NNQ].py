### 解题思路
> 依次处理 空格， +-符号位， 溢出判定 等

### 代码

```python3

class Solution:
    def myAtoi(self, s: str) -> int:
        if not s:
            return 0
        neg = False
        start = 0
        while start < len(s) and s[start] == ' ':
            start += 1
        if start == len(s):
            return 0
        if s[start] == '-':
            neg = True
            start += 1
        elif s[start] == '+':
            start += 1
        s = s[start:]
        num = 0
        pos_max = 2147483647
        neg_max = -2147483648
        checker = 2147483647 // 10
        last = 8 if neg else 7
        for i in s:
            if '0' <= i <= '9':
                curr = int(i)
                if num > checker or (num == checker and curr > last):
                    return neg_max if neg else pos_max
                num = num * 10 + curr
            else:
                break
        return -num if neg else num


```

### time
```
执行用时 :52 ms, 在所有 Python3 提交中击败了27.31%的用户
内存消耗 :13.7 MB, 在所有 Python3 提交中击败了5.02%的用户
```