### 解题思路
python 中字符串本身也是一种列表，可迭代

### 代码

```python3
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        sum_ = 0
        mul = 1
        nn = str(n)
        for i in nn:
            sum_ += int(i)
            mul *= int(i)

        return(mul-sum_)
```