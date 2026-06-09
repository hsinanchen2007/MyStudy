### 解题思路
本题参考了第7题（整数反转）的方法，让一个变量y存储形参x的反转，由题意知回文数的反转等于它本身。
首先负数有负号，不可能是回文数，返回false。
再判断x的反转是否与x相等，若相等则为回文数，返回true;否则不是回文数返回false。
注意：Python2中true和false的头字母要大写！大写才符合语法规范，它们到json文件中会自动变成小写，输出小写的true、false，可以满足题目的要求。

### 代码
```python
class Solution(object):
    def isPalindrome(self, x):#判断回文数
        """
        :type x: int
        :rtype: bool
        """
        if x<0:#负数不可能是回文数
            return False
        else:
            temp=x
            y=0
            lens=len(str(x))#x的位数
            i=lens-1
            for i in range(lens):
                y=y*10+temp%10#y是x的反转
                temp=temp/10
                i-=1
            if y==x:#相等即为回文数
                return True
            else:
                return False
```