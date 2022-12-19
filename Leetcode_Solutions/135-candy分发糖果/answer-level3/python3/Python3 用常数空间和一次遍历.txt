注意边界条件检查，山谷的重复。
```python3 []
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        cnt = 0
        up = 0
        down = 0
        gu = 0
        for i in range(n-1):
            if ratings[i]<ratings[i+1]:
                if down>0:
                    slope = max(up,down)
                    cnt += up*(up-1)//2
                    cnt += down*(down-1)//2
                    cnt += slope
                    up, down = 0, 0
                    gu += 1
                if up == 0:
                    up += 2
                else:
                    up += 1
            elif ratings[i]>ratings[i+1]:
                if down == 0:
                    down += 2
                else:
                    down += 1
            else:
                if up==0 and down==0:
                    cnt += 1
                else:
                    slope = max(up,down)
                    cnt += up*(up-1)//2
                    cnt += down*(down-1)//2
                    cnt += slope
                    up, down = 0, 0
        if up>0 or down>0:
            slope = max(up,down)
            cnt += up*(up-1)//2
            cnt += down*(down-1)//2
            cnt += slope
        else:
            cnt += 1
        return cnt-gu
```