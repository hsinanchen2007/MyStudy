### 解题思路
也不算太暴力。对不是10的倍数的数可以按照常规方法进行条件分析;对于10的倍数的数字使用while语句进行循环，先不要判断正负，之后使用if再次进行正负判断。最后的结果不算太差。

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        if -2147483648 > x or x> 2147483647 or x==0 :
             return 0
        if x>0 and x%10!=0:
            x=int(str(x)[::-1])
            return x if -2147483648 < x < 2147483647 else 0
        if x<0 and x%10!=0:
            x=int(str(abs(x))[::-1])*-1
            return x if -2147483648 < x < 2147483647 else 0
        while x%10==0 :
            x = int(x/ 10)
        if x>0:
            x=int(str(x)[::-1])
            return x if -2147483648 < x < 2147483647 else 0
        elif x<0:
            x=-x
            x='-'+str(x)[::-1] #也可以使用其他方法，暂不列出
            x=int(x)
            return x if -2147483648 < x < 2147483647 else 0
           


```