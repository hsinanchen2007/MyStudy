### 解题思路
其实我们只需要A中的最大值和最小值就可以了，如果最大值减去k可以小于或者等于最小值加上k。那么A中所有元素就可以都变成一样。差值就为0，否则差值就等于(max(A)-k) - (min(A)+k)

### 代码

```python3
class Solution:
    def smallestRangeI(self, A: List[int], K: int) -> int:
         result = (max(A)-k) - (min(A)+k)
         if result >=0:
             return result
         else:
             return 0
```