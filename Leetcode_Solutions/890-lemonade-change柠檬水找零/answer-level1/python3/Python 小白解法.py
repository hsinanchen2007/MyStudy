```
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        if bills[0]!=5:
            return False
        five = 1
        ten = 0
        for i in range(1,len(bills)):
            if bills[i]==5:
                five += 1
            elif bills[i]==10:
                ten+=1
                five-=1
                if five < 0:
                    return False
            else:
                if ten-1 >= 0 and five-1>=0:
                    ten -= 1
                    five -= 1
                elif five -3>=0:
                    five -= 3
                else:
                    return False
        return True
            
        
```
