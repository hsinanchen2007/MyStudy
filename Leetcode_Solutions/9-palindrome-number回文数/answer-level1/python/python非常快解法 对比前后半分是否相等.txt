```
class Solution(object):
    def isPalindrome(self, x):

        if x<0 or (x and x%10==0):
            return False
        y=0
        #只用比前半部分正序==后半部分倒序，节省一半时间
        while x>y: #x是前半部分 y是后半部分
            y=10*y+x%10 #整数部分左移+余数 从最后一个数字开始
            #print("y:",y)
            x=x//10 #从前往后整数部分
            #print("x:",x)
        return x==y or x==y//10 #x==y是偶数 x==y//10是奇数
```
