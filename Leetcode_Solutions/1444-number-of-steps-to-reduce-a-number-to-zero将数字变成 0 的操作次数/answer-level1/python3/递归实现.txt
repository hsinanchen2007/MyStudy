递归实现：
如果为0 ， 则返回0
否则返回递归 结果 + 1. 

class Solution:
    def numberOfSteps (self, num: int) -> int:
        if num == 0:
            return 0
        elif num % 2 == 0:
            return self.numberOfSteps(num/2) + 1
        else:
            return self.numberOfSteps(num -1) + 1