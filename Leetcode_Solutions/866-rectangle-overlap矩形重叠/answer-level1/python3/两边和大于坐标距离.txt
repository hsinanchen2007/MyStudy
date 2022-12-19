执行用时 :24 ms, 在所有 python3 提交中击败了100.00%的用户
内存消耗 :12.7 MB, 在所有 python3 提交中击败了100.00%的用户

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        a = rec1[-1]-rec1[1]+rec2[-1]-rec2[1]>max(abs(rec1[1]-rec2[-1]),abs(rec2[1]-rec1[-1]))
        b = rec1[-2]-rec1[0]+rec2[-2]-rec2[0]>max(abs(rec1[0]-rec2[-2]),abs(rec2[0]-rec1[-2]))
        return a and b
```