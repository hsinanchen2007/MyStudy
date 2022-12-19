class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        a = str(x)
        l = list(a)
        n = len(a)
        if x > 0:
            i = 0
            j = n-1
            while i < j:
                l[i],l[j] = l[j],l[i]
                i+=1
                j-=1
        elif x<0:
            i=1
            j =n-1
            while i < j:
                l[i],l[j] = l[j],l[i]
                i+=1
                j-=1
        else:
            return x
        aa = ''.join(l)
        xx = int(aa)
        if xx<=(-2**31) or xx>(2**31-1):
            return 0
        else:
            return xx


解法的几个思路：
    1，先将整数转化为字符串，再将字符串转化为列表（小白只会处理列表）
    2，通过判断输入的值来确定x的三种情况（正数、负数、0）
    3，根据三种不同情况，主要利用while循环来写
    4，最后通过if判断翻转的整数是否出界，如果出界返回0

小白一枚，如有高见，还请指教~