### 解题思路
尾随零本质是阶乘中“10=2*5的个数”。2的个数肯定小于5的个数，所以尾随零取决于5的个数

### 代码

```python3
class Solution:
    def trailingZeroes(self, n: int) -> int:
        # 2的个数肯定小于5的个数，所以尾随零取决于5的个数
        cnt = 0
        divider = 5
        while n // divider:
            cnt += n // divider
            # 计算1~n中为5,25,125...的倍数的个数
            divider *= 5
        return cnt
```