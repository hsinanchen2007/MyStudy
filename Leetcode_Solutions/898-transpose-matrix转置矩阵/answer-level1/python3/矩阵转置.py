时间是有点长。望指正。
```
class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        temp=[]
        temp += list(zip(*A))
        return temp
```
