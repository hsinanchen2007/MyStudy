### 解题思路
分情况讨论
### 代码

```python3
class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        ans = []
        while A and B:
            a = A[0]
            b = B[0]
            if a[0] >= b[0] and a[1] <= b[1]:
                ans.append([a[0], a[1]])
                A.pop(0)
            elif b[0] < a[1] < b[1]:
                ans.append([b[0],a[1]])
                A.pop(0)
            elif a[1] == b[0]:
                ans.append([a[1],b[0]])
                A.pop(0)
            elif b[0] >= a[0] and b[1] <= a[1]:
                ans.append([b[0],b[1]])
                B.pop(0)
            elif b[0] < a[0] < b[1]:
                ans.append([a[0],b[1]])
                B.pop(0)
            elif b[1] == a[0]:
                ans.append([b[1],a[0]])
                B.pop(0)
            elif b[1] < a[0]:
                B.pop(0)
            elif b[0] > a[1]:
                A.pop(0)
        return ans
```