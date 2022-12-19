**思路：**

直接模拟，因为`A[i]`值较大，所以将`[3,8,0,9,2,5]`映射成`[8,8,8,5,5]`存储的方式不可取，会导致内存溢出。所以应该将`A`直接存储，每次调用`next`时候，从数组头部开始检查，如果`A[0]`小于`n`，则将`A[0]`和`A[1]`移除队列，并将`n`自身减去`A[0]`，直到检查到`A[0]`大于等于`n`，记最后被耗去的项是`A[1]`，并将`A[0]`减去`n`。

时间复杂度$O(N)$

空间复杂度$O(N)$

**图解：**

![图解](https://pic.leetcode-cn.com/0c7607c92003ac0bf9b690812460b1ce38103567200b52fdb5e2a1d4fcfa9da9.gif)

**代码：**

```python
class RLEIterator:

    def __init__(self, A):
        """
        :type A: List[int]
        """
        self.RLE = A

    def next(self, n):
        """
        :type n: int
        :rtype: int
        """
        last = -1
        while self.RLE and self.RLE[0] < n:
            n -= self.RLE[0]
            self.RLE = self.RLE[2:]

        if self.RLE:
            last = self.RLE[1]
            self.RLE[0] -= n
            while self.RLE[0] == 0:
                self.RLE = self.RLE[2:]

        return last


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(A)
# param_1 = obj.next(n)
```