### 解题思路
1将数字转化成字符串
2 正负和0 的三种情况分开考虑
  并且在内判断是否超出题干规定
3 正数的情况直接用反向截取字符串的方法
4负数的情况先转化成正数，颠倒后再加上负号
简单粗暴的解法，希望大家多多指正


### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        a = str(x)
        if x > 0 :
            a = a[::-1]
            e = int(a)
            if e > (2**31)-1:
                return 0
            return e
        elif x < 0 :
            b = -x
            c = str(b)
            c = c[::-1]
            d =-int(c)
            if d <-2**31:
                return 0
            return d
        elif x== 0:
            return x
        else:
            return 0
```