class Solution:
    def findClosedNumbers(self, num: int) -> List[int]:
         
        left, right = num+1, num-1

        n = bin(num).count('1')

        while(bin(left).count('1')!= n):   left += 1

        while(right > 0 and bin(right).count('1')!= n ):  right -= 1


        right = -1 if right == 0 else right
        
        return left,right