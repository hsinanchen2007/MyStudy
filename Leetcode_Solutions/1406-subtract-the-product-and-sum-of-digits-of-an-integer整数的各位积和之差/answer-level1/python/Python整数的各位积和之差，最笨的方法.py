### 解题思路
此处撰写解题思路：最笨的方法：1.把每一位提取出来，2.再考虑到特殊情况801和超出n值范围。

### 代码

```python
class Solution(object):
    def subtractProductAndSum(self, n):

        """
        :type n: int
        :rtype: int
        """
        x1=n//100000    #十万位
        x2=(n%100000)//10000     #万位
        x3=(n%10000)//1000    #千位
        x4=(n%1000)//100     #百位
        x5=(n%100)//10    #十位
        x6=(n%10)//1    #个位
        if n>=1 and n<=100000:
            if x1==0 and x2!=0:
                return((x2*x3*x4*x5*x6)-(x2+x3+x4+x5+x6))
            elif x1==0 and x2==0 and x3!=0:
                return((x3*x4*x5*x6)-(x3+x4+x5+x6))
            elif x1==0 and x2==0 and x3==0 and x4!=0:
                return((x4*x5*x6)-(x4+x5+x6))
            elif x1==0 and x2==0 and x3==0 and x4==0 and x5!=0:
                return((x5*x6)-(x5+x6))
            elif x1==0 and x2==0 and x3==0 and x4==0 and x5==0 and x6!=0:
                return((x6)-(x6))
            else:
                return((x1*x2*x3*x4*x5*x6)-(x1+x2+x3+x4+x5+x6))
        else:
            return False
```