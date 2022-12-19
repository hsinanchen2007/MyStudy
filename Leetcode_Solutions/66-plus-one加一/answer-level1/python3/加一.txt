### 解题思路
1.先判断列表元素是否全部是9
2.列表最后一个元素加1
3.如果加一后最后一个元素大于9则遍历列表并且当前元素等于0，前一个元素加一

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if digits == [9 for j in range(len(digits))]:
            digits = [0 for x in range(len(digits))]
            digits.insert(0,1)
            return digits
        digits[-1] += 1
        for i in range(len(digits),-1,-1):
            if digits[i-1] > 9:
                digits[i-1] = 0
                digits[i-2] += 1
        return digits


```