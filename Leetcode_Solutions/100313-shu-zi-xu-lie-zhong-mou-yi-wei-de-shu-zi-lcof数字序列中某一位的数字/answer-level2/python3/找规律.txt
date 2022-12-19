```python
class Solution:
    def findNthDigit(self, n: int) -> int:
        if n < 10: return n 
        count = 0
        i = 1
        base = 9
        # 先找到处于几位数
        while count + base * i < n:
            count += base * i 
            base *= 10
            i += 1
        rest = n - count 
        # 计算出处于几位数的第几个，并且在确定的数字中的第几位
        add, remainder = divmod(rest, i)
        cur = base // 9 + add 
        if remainder == 0:
            return int(str(cur-1)[-1])
        else:
            return int(str(cur)[remainder-1])
```