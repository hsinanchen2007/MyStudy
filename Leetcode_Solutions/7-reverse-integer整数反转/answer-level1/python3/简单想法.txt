class Solution:
    def reverse(self, x: int) -> int:
        tList = list(str(x))
        if tList[0] == '-':
            rNum = int(''.join(tList[1:][::-1])) * (-1)
        else:
            rNum = int(''.join(tList[::-1]))
    
        if rNum in range(pow(2,31)*(-1),pow(2,31)-1):
            return rNum
        else:
            return 0```javascript []

