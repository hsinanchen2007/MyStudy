### 解题思路
题目要求阶乘尾数 0 的数量，实际上是2*5的数量，换言之就是5的数量

### 代码

```python3
class Solution:
    def trailingZeroes(self, n: int) -> int:
        i = 1
        num = 0
        while int(n/(pow(5,i))) != 0:
            num += int(n/(pow(5,i)))
            i += 1
        return num

```