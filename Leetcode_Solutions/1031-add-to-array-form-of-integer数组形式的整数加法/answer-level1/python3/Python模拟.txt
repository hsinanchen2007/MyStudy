### 解题思路
把给定的整数转化成列表，两个列表都反过来，从个位数开始加呗，到这一步已经变成了大整形计算的模板题。

### 代码

```python3
class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        k = []
        while K:
            k.append(K % 10)
            K //= 10
        a = A[::-1]
        if len(a) > len(k):
            a, k = k, a
        r = 0
        for i in range(len(k)):
            if i < len(a):
                k[i] += a[i]
            k[i] += r
            r = k[i] // 10
            k[i] %= 10
        if r:
            k.append(r)
        return k[::-1]
```