### 解题思路
时间复杂度：O(m+n)
空间复杂度：O（1）

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        int_a = 0
        int_b = 0
        for idx, i in enumerate(a[::-1]):
            int_a += int(i) * 2**idx
        for idx, i in enumerate(b[::-1]):
            int_b += int(i) * 2**idx
        int_c = int_a + int_b

        if int_c == 0:
            return "0"
        rstr = ""
        while int_c > 0:
            m, n = divmod(int_c, 2)
            rstr += str(n)
            int_c = m
        return rstr[::-1] 

```