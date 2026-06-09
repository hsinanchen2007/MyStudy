### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        sum = 0
        ml = 1
        while n >0 :
            k = n%10
            ml *= k
            sum += k
            n = (n-k)/10
        s = ml - sum
        return int(s)
```