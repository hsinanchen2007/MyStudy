### 解题思路
两个指针逐个遍历, 
要留意移动过程中

### 代码

```python3
class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        res = []
        i = j = 0
        la, lb = len(A), len(B)
        while i<la and j<lb:
            sa, sb = A[i][0], B[j][0]
            ea, eb = A[i][1], B[j][1]
            start, end = max(sa, sb), min(ea, eb)
            if start<=end: # 要小心这种情况!  a[i].end < b[j+1].start
                res.append([start, end])
            if ea>eb: j += 1
            elif ea<eb: i += 1
            else: i, j = i+1, j+1
        return res            
```