### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        output = digits[:]
        output[-1] += 1
        #末位带进位的情况
        if digits[-1] == 9:
            n = len(digits)
            carry = 1
            for i in range(n - 1, -1, -1):
                a = digits[i] + carry
                output[i] = a % 10
                carry = a // 10
                if carry == 0:
                    break
            if carry != 0:
                output.insert(0, 1)
        return output

```