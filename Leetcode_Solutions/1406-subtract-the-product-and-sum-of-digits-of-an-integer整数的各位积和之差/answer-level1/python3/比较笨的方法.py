### 解题思路
比较笨的方案，先把这个整数转换成数组，然后遍历。

在求乘积和求和的时候，再将对应数组里面的元素转换为int。最后输出。。。


### 代码

```python3
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        product = 1
        summation = 0
        L = len(list(str(n)))
        for i in range(L):
            product = product * int(list(str(n))[i])
            summation = summation + int(list(str(n))[i])
        return (product-summation)

```