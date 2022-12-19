### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        def backtrace(st,ed,track,target,k):
            if track:
                tmp=track.copy()
                tmp.sort()
            if sum(track)==target and len(track)==k and tmp not in res:
                res.append(tmp)
            for i in range(st,ed+1):
                if i in track:
                    continue
                if len(track)>k:
                    return
                track.append(i)
                backtrace(st+1,ed,track,target,k)
                track.pop()
        res=[]
        track=[]
        backtrace(1,9,track,n,k)
        return res

```