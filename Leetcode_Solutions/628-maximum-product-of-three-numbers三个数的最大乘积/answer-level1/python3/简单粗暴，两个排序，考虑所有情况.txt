```
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        if len(nums) <= 3:
            return nums[-1]*nums[-2]*nums[-3]
        num1 = []
        num2 = []
        for i in nums:
            if i < 0:
                num1.append(i)
            else:
                num2.append(i)
        num1.sort()
        num2.sort()
        if len(num1) < 2:
            return num2[-1]*num2[-2]*num2[-3]
        elif len(num2) < 3:
            return num1[0]*num1[1]*num2[-1]
        else:
            return num1[0]*num1[1]*num2[-1] if num1[0]*num1[1]*num2[-1] > num2[-1]*num2[-2]*num2[-3] else num2[-1]*num2[-2]*num2[-3]
```
