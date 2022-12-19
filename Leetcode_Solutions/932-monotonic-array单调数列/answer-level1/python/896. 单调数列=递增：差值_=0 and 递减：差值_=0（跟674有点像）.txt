### 解题思路
1. 非常要注意的一点，判断是否输入数列长度为1.
2. 计算两两之间的差值
3. min(差值) 大于等于0（说明单调递增），或是max(差值)小于等于0（说明单调递减），return True

### 代码

```python3
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        if len(A) == 1:
            return True

        d_value = []
        for idx in range(1, len(A)):
            d_value.append(A[idx]-A[idx-1])
        
        if min(d_value) >= 0 or max(d_value) <= 0:
            return True 
        
        return False
```