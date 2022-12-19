### 解题思路
如果直接使用self.myPow(x, n / 2) * self.myPow(x, n / 2)的话，还是调用了两次的计算
这样的话并没有减少计算的计算的次数
应该使用temp = self.myPow(x, n / 2)，然后temp * temp才能减少计算的次数

### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0:
            return 0
        if n == 0:
            return 1
        if n < 0:
            return self.myPow(1 / x, -n)
        if n % 2 == 0:
            temp =  self.myPow(x, n / 2)
            return temp * temp
        else:
            temp =  self.myPow(x, (n - 1) / 2)
            return temp * temp * x
    #快速幂算法，时间复杂度为log(n)，这样计算下来比较快
    #如果直接使用self.myPow(x, n / 2) * self.myPow(x, n / 2)的话，还是调用了两次的计算
    #使用上面的那种方式才是减少了计算
```