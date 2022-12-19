判断最后一位是不是9，如果不是直接加一，如果是
先把最后一位变成0
判断digits的长度是否大于1，
是：
   plusOne(最后一位前面的list)
否则：
   在前面插入个1
返回


```python []
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if digits[-1] + 1 == 10 :
            digits[-1] = 0
            if len(digits) > 1:
                digits[:len(digits) - 1] = self.plusOne(digits[:len(digits) - 1])
            else:
                digits.insert(0,1)        
        else:
            digits[-1] += 1
        return digits 


```

