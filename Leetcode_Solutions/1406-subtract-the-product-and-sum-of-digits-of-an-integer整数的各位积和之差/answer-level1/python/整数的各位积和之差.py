### 解题思路
将整数转化为字符串，然后将其中每个字符转为整数，然后遍历求积，求和可以直接用sum函数。

### 代码

```python3
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        lis = [ int(i) for i in str(n)]
        s  =1
        for i in lis:
            s *= i
        return s -sum(lis)
```