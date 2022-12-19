### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        a = b = 0
        ans = []
        while a < len(A) and b < len(B):
            if A[a][1] < B[b][0]:
                a += 1
            elif A[a][0] > B[b][1]:
                b += 1
            else:
                ans.append([max(A[a][0], B[b][0]), min(A[a][1], B[b][1])])
                if A[a][1] < B[b][1]:
                    a += 1
                elif A[a][1] > B[b][1]:
                    b += 1
                else:
                    a += 1
                    b += 1
        return ans




```