### 解题思路
判斷AB哪個大哪個小
來去使用方案A或方案B

### 代码

```python3
class Solution:
    def multiply(self, A: int, B: int) -> int:
        def projectA(AA, AB):
            if AB<=1:return AA
            return AA+projectA(AA, AB-1)
        def projectB(BA, BB):
            if BA<=1:return BB
            return BB+projectB(BA-1, BB)
        if A<B:
            return projectB(A, B)
        else:
            return projectA(A, B)
```