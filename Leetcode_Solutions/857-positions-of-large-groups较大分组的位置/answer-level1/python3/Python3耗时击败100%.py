from itertools import groupby
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        arr=[list(g) for k, g in groupby(S)]
        start=0
        ans=[]
        for i in arr:
            l=len(i)
            if l>=3:
                ans.append([start,start+l-1])
            start+=l
        return ans