```python
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        segments = S.split(C)
        st_seg, ed_seg = segments[0], segments[-1]
        res = [i for i in range(len(st_seg), 0, -1)] + [0]
        for seg in segments[1:-1]:
            n = len(seg)
            tmp = [i for i in range(1, n//2+1)] + [i for i in range(n-n//2, 0, -1)] + [0]
            res.extend(tmp)
        res.extend([i for i in range(1, len(ed_seg)+1)])
        return res
```