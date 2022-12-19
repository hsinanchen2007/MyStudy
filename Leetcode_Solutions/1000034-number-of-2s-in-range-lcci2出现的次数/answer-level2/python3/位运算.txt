### 解题思路
- 根据每一位b来计算当前位为2时候的个数(只考虑当前位的2)
- 对于xby来说, 需要判断b与2的大小, 左边部分的个数是int(x), 如果b>2的话需要+1(即0~x之间的所有数都满足), 右边部分为10**len(y), 左边部分*右边部分的个数即为所求
- 注意需要特殊处理b==2的情况, 需要加上左边部分恰好为x时右边的个数, 即为int(y)+1

### 代码

```python
class Solution:
    def numberOf2sInRange(self, n: int) -> int:
        res = 0
        s = str(n)
        for i in range(len(s))[::-1]:
            c = s[i]
            left = 0 if i == 0 else int(s[0:i])
            if c > '2':
                left += 1
            res += left * (10**(len(s) - i - 1))
            if c == '2':
                right = int(s[i + 1:]) + 1 if i + 1 < len(s) else 1
                res += right
        return res
```