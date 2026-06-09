num先转string，取出每一位累加，再递归一波， 时间复杂度97%，空间100%
class Solution:
    def addDigits(self, num: int) -> int:
        if num < 10:
            return num
        
        numStr = str(num)
        sum = 0

        for i in numStr:
            sum += int(i)
        
        return self.addDigits(sum)