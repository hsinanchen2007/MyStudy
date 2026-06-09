### 解题思路
做题的想法都在注释里了

### 代码

```python
class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        #1位数有10个                   1-9
        #2位数有99-10+1=90个           10-189
        #3位数有999-100+1=900个        190-2889
        #4位数有9000个                 2890-38889
        #5位数有90000个                38890-488889
        #step1 先看属于哪一个范围


        l=len(str(n))

        #n=123为例
        #先看对应几位数
        l=1
        big=9
        start=1
        while n>big:
            start=big+1
            l+=1
            big=big+10**(l-1)*l*9
            # print big,'big'
        # print '几位数:',l

        #第123位。对应表中是2位数
        #123是101之后第几个数呢
        pre=10**(l-1)
        # print start,big
        num,pos=divmod(n-start,l)
        # print '第{}个数，第{}位'.format(num,pos)
        target=pre+num
        # print target
        return str(target)[pos]


```