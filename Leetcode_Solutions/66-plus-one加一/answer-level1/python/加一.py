#利用最原始暴力的方法，直接从最高位便利，分为三种情况
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        n=len(digits)
        i=n-1
        while(i>=0):
            if(digits[i]!=9):
                digits[i]=digits[i]+1
                break
            elif i==0 :
                digits[i]=(digits[i]+1)%10
                digits.insert(0,1)
                break
            else:
                digits[i]=(digits[i]+1)%10
                i=i-1
        return digits
        
                

            

