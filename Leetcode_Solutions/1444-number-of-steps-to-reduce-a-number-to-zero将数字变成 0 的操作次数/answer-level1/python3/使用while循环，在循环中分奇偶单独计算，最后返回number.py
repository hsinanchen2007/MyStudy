class Solution:
    def numberOfSteps (self, num: int) -> int:
        number = 0
        while num > 0:
            if num%2 == 0:
                num = num/2
                number += 1
            else:
                num = num -1
                number += 1
        return number