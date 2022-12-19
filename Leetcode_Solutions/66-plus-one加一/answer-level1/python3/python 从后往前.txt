思路：从后往前判断数字等不等于9，如果等于再往前一位判断。不等于就直接加1退出。
```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if not digits:
            return [1]
        n = len(digits)
        for i in range(n-1,-1,-1):
            if digits[i] == 9:
                digits[i] = 0
            else:
                digits[i] += 1
                break
        if digits[0] == 0:
            digits.insert(0, 1)
        return digits
```
