```
class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        R=B=G=0
        for r,b,g in costs:
            nr=r+min(B,G)
            nb=b+min(R,G)
            ng=g+min(B,R)
            R,B,G=nr,nb,ng
        return min(R,B,G)
```
不清楚的话看O(n)版本：
```
class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        R,B,G=[0],[0],[0]
        for r,b,g in costs:
            nr=r+min(B[-1],G[-1])
            nb=b+min(R[-1],G[-1])
            ng=g+min(B[-1],R[-1])
            R,B,G=R+[nr],B+[nb],G+[ng]
            # print(R,B,G)
        return min(R[-1],B[-1],G[-1])
```
