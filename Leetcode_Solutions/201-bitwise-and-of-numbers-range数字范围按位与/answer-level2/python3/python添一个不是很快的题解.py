### 解题思路
速度一般，感觉可以优化

### 代码

```python3
class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        b = bin(n)[2:]
        ans = ['1']*len(b)
        for i in range(len(b)):
            if b[i] == '0':
                ans[i] = '0'
            else:
                if i != len(b) - 1:
                    a = b[:i] + '0' + '1'*(len(b)-i-1)
                    if int(a,2) >= m:
                        ans[i] = '0'
                else:
                    a = b[:i] + '0'
                    if int(a,2) >= m:
                        ans[i] = '0'
        return int(''.join(ans),2)

```