### 递归实现
![image.png](https://pic.leetcode-cn.com/2f68e50c204cd47d3a208b41e06fb109d37994caef78d251589620cc6e380893-image.png)
- 递归实现的方法类似于<斐波那契数列>
- 加入我们要求`m`的`32`次方.如果我们知道了`m`的`16`次方,那么只要在这个基础上在平方就可以了.而`16`次方是`8`次方的平方......以此类推,这样我们就需要做`5`次乘法:
- 先求平方,在平方的基础上求`4`次方,在`4`次方的基础上求`8`次方,在`8`次方的基础上求`16`次方,最后在`16`次方的基础上求`32`次方.也就是如下递推公式:
- 
![WechatIMG12.jpeg](https://pic.leetcode-cn.com/2ffeec139a46c30fabea65187a8a84d5c9c65fb7ae0faeaee730de6f55618335-WechatIMG12.jpeg)

### 代码

```python
class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        redult = 0
        m = abs(n)
        def compute(x, m):
            if m == 0:
                return 1
            if m == 1:
                return x
            temp = compute(x, m >> 1)
            temp *= temp
            if m & 0x1 == 1:
                temp *= x
            return temp
        if n > 0:
            return compute(x, m)
        else:
            return 1 / compute(x, m)
            
          

            
   

        
```