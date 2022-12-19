执行用时 :252 ms, 在所有 Python 提交中击败了27.04% 的用户
内存消耗 :11.9 MB, 在所有 Python 提交中击败了33.74%的用户
```
class Solution(object):
    
    def __init__(self):
        self.five = []
        self.ten = []      
    
    def got_five(self):
        self.five.append(1)
    def got_ten(self):

        self.five.remove(1)
        self.ten.append(1) 
        
    def got_fif1(self):

        self.five = self.five[:-1]
        self.ten = self.ten[:-1]     
    def got_fif2(self):

        self.five = self.five[:-1]
        self.five = self.five[:-1]
        self.five = self.five[:-1] 
    
    def lemonadeChange(self, bills):
        """
        :type bills: List[int]
        :rtype: bool
        """
        if bills[0] == 10:
            return False
        for bill in bills:
            if bill ==5:
                self.got_five()
            elif bill ==10:
                if len(self.five) == 0:
                    return False
                self.got_ten()
            else:
                if len(self.five) >= 1  and  len(self.ten) != 0:
                    self.got_fif1()
                elif len(self.five) >= 3:
                    self.got_fif2()
                else:
                    return False
        return True
        


```
