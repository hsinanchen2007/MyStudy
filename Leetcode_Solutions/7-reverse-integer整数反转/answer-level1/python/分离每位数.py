### 解题思路
此处撰写解题思路
判断x的正负，决定输出正负号，剩下的绝对值部分就统一处理，自然是循环除以10求余数分离每一位，再把循环乘以10加起来，判断范围输出
### 代码

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        x_ = x
        x = abs(x)
        a = []
        s = 0
        c = 0
        while (x//10 !=0):
            t = x%10
            a.append(t)
            x = x//10
        a.append(x)
        for i in a:
            c = c+1
            s = s+i*10**(len(a)-c)
        if x_>=0:
            if s<2**31-1:
                return s
            else:
                return 0
        else:
            if s<2**31:
                return 0-s
            else:
                return 0
```