- 虽然不是最优的解法, 但是胜在结构清晰, 少了很多的判断;
- 这里的range的范围额外注意, 选择是是长的那个
- 还有就是n1和n2的值的确定
- 还有最后那个`carry==1`的情况

```python
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        carry = 0
        res = []
        for k in range(max(len(a), len(b))):
            i = len(a) - k - 1
            j = len(b) - k - 1

            n1 = int(a[i]) if i >= 0 else 0
            n2 = int(b[j]) if j >= 0 else 0

            sum = (n1 + n2 + carry)
            carry = sum // 2
            sum = sum % 2
            res.insert(0, str(sum))
        if carry == 1:
            res.insert(0, '1')
        return ''.join(res)
```

实际上, 这是一种比较通用的解法, 只要是逐位的, 都可以这么干