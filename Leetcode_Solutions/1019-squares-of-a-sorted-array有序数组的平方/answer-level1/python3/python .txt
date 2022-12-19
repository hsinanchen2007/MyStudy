### 解题思路
用python的话应该闭着眼睛都能做出来吧

### 代码

```python3
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        result = [i**2 for i in A]
        result.sort()
        return result
```