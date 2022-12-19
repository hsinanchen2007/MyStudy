一 算法思想
利用递归调用实现累加运算，并通过python中and运算在and前条件表达式不满足时不执行and后条件表达式的性质控制递归的边界。
二 算法实现
```
class Solution:
    def sumNums(self, n: int) -> int:
        self.sum = 0
        n > 0 and self.sumNums(n-1)
        self.sum += n
        return self.sum
```
三、复杂度分析
时间复杂度：O(N)。每层除递归语句外其余语句为常量时间复杂度，递归深度为N，所以总的时间复杂度为O(N)。
空间复杂度：O(N)。由于递归时所用栈的深度为N，所以空间复杂度为O(N)。