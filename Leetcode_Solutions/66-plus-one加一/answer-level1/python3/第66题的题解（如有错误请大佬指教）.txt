### 解题思路
考虑每一种情况并分别给出对策，小白纯暴力解法，没想到效果还不错！如果觉得对你有帮助的话可以点赞哟~

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        length = len(digits)
        if digits[0] == 0:
            return [1]
        while 9 not in digits:
            temp = digits[length - 1] + 1
            digits.pop()
            digits.append(temp)
            return digits
        else:
            if digits[length - 1] == 9 and length == 1:
                return [1, 0]
            elif digits[length - 1] == 9 and length != 1:
                
                count = 0
                for i in range(length - 2, -1, -1):
                    if digits[i] == 9:
                        digits[i + 1] = 0
                        digits[i] = 0
                        count += 1

                        if count == length - 1:
                            digits.insert(0, 1)
                            return digits
                    else:
                        digits[i + 1] = 0
                        digits[i] = digits[i] + 1
                        break

                return digits
            else:
                temp = digits[length - 1] + 1
                digits.pop()
                digits.append(temp)
                return digits
```