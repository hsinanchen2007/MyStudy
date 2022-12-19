### 解题思路
考虑到空数组和数组未发生旋转的两种特殊情况。

### 代码

```python3
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        n = len(numbers)
        if n == 0:
            return 0
        for i in range(1,n):
            if numbers[i] < numbers[i-1]:
                return numbers[i]
        return numbers[0]
        
```