### 解题思路
题目的考点在于，如何保存nums并在类内共享使用。因为init函数不允许传递返回值，所以必须使用self.num变量保存nums。并通过self.XXX来传递给其他类内方法使用。

### 代码

```python3
class NumArray:

    def __init__(self, nums: List[int]):
        self.num = nums

    def sumRange(self, i: int, j: int) -> int:
        sum = 0
        for k in range(i, j+1):
            sum += self.num[k]
        return sum


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
```