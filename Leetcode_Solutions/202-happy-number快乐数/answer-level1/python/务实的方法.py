注意 判断退出的条件 ：
      将每次得到的数放入列表，如果已存在 说明该数进入死循环，是不快乐数 此时应返回False
      如果得到数1  返回True
常规代码如下：
```python
# -*- coding:utf-8 -*-
# @Author  : Clint
def isHappy(self, n):
    sum = 0
    li = [n, ]
    while n != 1:
        while n != 0:
            n, b = divmod(n, 10)     # n除以10得到除数赋值给n，余数赋值给b
            sum += b**2
        if sum == 1:
            return True
        else:
            if sum not in li:
                li.append(sum)
                n = sum
                sum = 0
            else:
                return False
```