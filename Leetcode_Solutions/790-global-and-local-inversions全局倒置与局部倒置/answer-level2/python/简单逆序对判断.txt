
-   逆序对判断

全局倒置就等于求解逆序对的数量

局部倒置就是相邻元素的倒置

如果想让全局倒置等于局部倒置，只能是数组中相邻元素进行交换，判断这个规则即可

```python
class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        length = len(A)
        index = 0
        while index < length:
            if index != A[index]:
                if index != A[index + 1] or A[index] != index + 1:
                    return False
                else:
                    index += 2
            else:
                index += 1
        return True
```

-   使用树状数组求解

```
下面代码在python2中通过，python3中超时
```

```python
class BinaryIndexTree:
    def __init__(self, num):
        """
        :type nums: List[int]
        """

        self.buff = [0] * (num + 1)

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: void
        """
        index = i + 1
        while index < len(self.buff):
            self.buff[index] += val
            index += index & (-index)

    def getSum(self, index):
        index += 1
        res = 0
        while index > 0:
            res += self.buff[index]
            index -= index & (-index)
        return res


class Solution:
    def isIdealPermutation(self, A):
        bit = BinaryIndexTree(len(A))

        total = 0
        neighbor = 0

        bit.update(A[0], 1)

        for index in range(1, len(A)):
            if A[index] < A[index - 1]:
                neighbor += 1
            bit.update(A[index], 1)
            total += index + 1 - bit.getSum(A[index])

        return total == neighbor


```


