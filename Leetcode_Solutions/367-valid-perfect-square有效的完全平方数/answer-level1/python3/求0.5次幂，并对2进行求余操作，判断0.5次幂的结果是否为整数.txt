
class Solution:
    
    def isPerfectSquare(self, num: int) -> bool:
        
        sqrt_root = num**0.5
        
        if sqrt_root % 2 == 0 or (sqrt_root -1) % 2 == 0:
            
            return(True)
        
        else:
            
            return(False)
