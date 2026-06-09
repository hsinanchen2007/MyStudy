class Solution:
    def addDigits(self, num: int) -> int:
        sums=0
        for i in str(num):
            sums+=int(i)
        if sums<10:
            return sums
        else:
            return self.addDigits(sums)