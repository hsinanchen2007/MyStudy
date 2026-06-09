### 解题思路
就是数连乘中5的个数.
因为连乘中每隔5个就有一个数可以被5整除, 所以除以5统计有多少个数
而有的数比如25可以被5整除两次, 所以要多除一次

### 代码

```python3
class Solution:
    def trailingZeroes(self, n: int) -> int:
        count = 0
        while n>=5:
            count += n//5
            n //= 5
        return count

```