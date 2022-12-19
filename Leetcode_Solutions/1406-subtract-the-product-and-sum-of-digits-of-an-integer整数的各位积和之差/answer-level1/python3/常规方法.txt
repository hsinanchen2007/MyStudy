### 解题思路
直接转成字符串再遍历

### 代码

```python3
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        stringn=str(n)
        product=1
        total=0
        for i in range(len(stringn)):
            product=product*int(stringn[i])
            total=total+int(stringn[i])
        return product-total
```