### 解题思路
1、这里使用基本的数学方法，直接进行翻转，类似栈一样的
2、这里需要注意下面两点：
  2.1 在计算过程中多判断一下，res如果在计算过程中出现溢出，也是0，由于Python对这个不明感所以需要注意。
  2.2 这里小于0可以进行其他判断，不需要我这样，我把这个发出来主要是提醒大家，python中 // 和 % 计算和其他的不一样。
```python3
      -12 // 10 = -2  --> -(-12 // -10) = -1
      -12 % 10 = 8  --> -12 % -10 = -2
```
3、我提交这个只是为了记录与提醒上面这个不同，其实这个效果一般。

### 代码

```python3
class Solution:
    def reverse(self, num: int) -> int:
        max_ = 2 ** 31 - 1
        min_ = -2 ** 31
        res = 0
        while num != 0:
            if num > 0:
                pop = num % 10
                num //= 10
            else:
                pop = num % -10
                num = - (num // -10)
            if min_ < res < max_:
                res = res * 10 + pop
            else:
                return 0
        return res if min_ < res < max_ else 0
```

