整体思路就是向前遍历，给最后一位+1，若+1后变成小于10的数，则说明其他位不需要改变，退出循环，否则继续执行循环，给前一位的数+1,以此类推

```python []
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits)-1, -1, -1):
            digits[i] += 1
            if digits[i] < 10:
                break
            else:
                digits[i] = 0
        if digits[0] == 0:          """这里针对首位因为加1变成0的情况，如[9,9]因为加一变成[0,0]"""
            digits = [1] + digits
        return digits
```
