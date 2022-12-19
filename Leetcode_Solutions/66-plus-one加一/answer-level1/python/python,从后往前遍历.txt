通过提前在队列头插入一个元素来规避全是9的溢出情况

class Solution(object):
    def plusOne(self, digits):
        digits.insert(0,0)
        i=len(digits)-1
        if digits[i] == 9 :
            while digits[i] == 9:
                i-=1
            digits[i]+=1
            for h in range(i+1,len(digits)):
                digits[h]=0
        else:
            digits[len(digits)-1]+=1
        if digits[0]==0:
            digits.pop(0)
        return digits
        