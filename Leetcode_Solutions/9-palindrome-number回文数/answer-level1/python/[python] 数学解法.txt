1.用python最简单的解法就是直接变字符串倒转判断是不是相等，很简单；
2.数学解法的思路是每次对10求余数，并且把余数再乘10构造新数，当原来的数不大于构造的数时，再进行比较；
3.在x为偶数时，显然二者相等；当x为奇数时，新构造的数会多一位最中间的数。
代码如下：
```
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0 or (x % 10 ==0 and x != 0):
            return False
        
        res = 0
        
        while x > res:
            res = res * 10 + x % 10
            x = x / 10
        
        return x == res or x == res / 10
```
