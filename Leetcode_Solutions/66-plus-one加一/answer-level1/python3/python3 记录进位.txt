
数字+1就要考虑到进位的问题，那么对数组从后往前逆序遍历，然后在最后一位添加1，并以此记录进位情况

```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        
        tmp = 0
        carry = 1
        
        for i in range(len(digits)-1, -1, -1):
            tmp = digits[i] + carry
            carry = tmp // 10
            digits[i] = tmp % 10
            
        # 如果首位仍进位，那么需要再添加一位
        if carry > 0:
            return [1] + digits
            
        return digits
```
