class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num==1:
            return True
        a = 1
        b = num
     
        while a<=b:
            mid = (a+b)//2
            if mid*mid == num:
                return True
            elif mid*mid>num:
                b = mid-1
            else:
                a=mid+1
            
            
        return False