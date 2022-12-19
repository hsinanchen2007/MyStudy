### 解题思路
列表尾数加一，此后找到列表中的10，其本身修改为0，前位加1

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits[-1] = digits[-1]+1
        while 10 in digits:
            if digits.index(10)==0:
                digits[0] = 0
                digits = [1]+digits
            else:
                index = digits.index(10)
                digits[index] = 0
                digits[index-1] += 1            
        return digits


```