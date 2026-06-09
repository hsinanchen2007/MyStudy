class Solution:
    def addDigits(self, num: int) -> int:
        num=[int(i) for i in str(num)]  #把高位数字拆成1位数的数组
        if len(num)==1:
            return num[0]
        else:
            tmp=sum(num)
            return self.addDigits(tmp)