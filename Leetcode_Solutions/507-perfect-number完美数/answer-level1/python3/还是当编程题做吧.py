```
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num<=1:
            return False
        nums=[1]
        if not int(num**(0.5))**2==num:
            target=int(num**(0.5))+1
        else:
            nums.append(int(num**(0.5)))
            target=int(num**(0.5))

        for i in range(2,target):
            if not num%i:
                nums.append(i)
                nums.append(num//i)
        return sum(nums)==num
```
