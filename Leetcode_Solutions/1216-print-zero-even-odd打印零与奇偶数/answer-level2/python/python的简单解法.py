
```
class ZeroEvenOdd(object):
    def __init__(self, n):
        self.n = n
        self.flag = 0  # 一共需要输出多少个数字
        self.zeroNum, self.evenNum, self.oddNum = [],[],[]
        
    def res(self):
        if self.flag == 2*self.n:   # 当所有方法存放到对应数组后即进行输出
            for i in range(1, self.n+1):
                if i%2 == 1:   
                    self.zeroNum.pop()(0)   #  始终输出0
                    self.oddNum.pop()(i)    #  输出接着的奇数
                else:
                    self.zeroNum.pop()(0)   #  始终输出0
                    self.evenNum.pop()(i)   #  输出接着的偶数
    
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber):
        """
        :type printNumber: method
        :rtype: void
        """
        for i in range(self.n):
            self.zeroNum.append(printNumber)   # 将方法存入对应数组
            self.flag+=1
        self.res()
        
        
    def even(self, printNumber):
        """
        :type printNumber: method
        :rtype: void
        """
        num = self.n // 2
        for i in range(num):
            self.evenNum.append(printNumber)    # 将方法存入对应数组
            self.flag+=1
        self.res()
        
    def odd(self, printNumber):
        """
        :type printNumber: method
        :rtype: void
        """
        num = (self.n+1) // 2
        for i in range(num):
            self.oddNum.append(printNumber)         # 将方法存入对应数组
            self.flag+=1
        self.res()
```
