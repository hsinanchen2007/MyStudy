```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if triangle==[]:
            return 0
        height=triangle.__len__()
        if height==1:
            return triangle[0][0]

        pre=triangle[0]
        now=[]
        for i in range(1,height):
            now=triangle[i][:]
            for j in range(now.__len__()):
                if j==0:
                    now[j]=now[j]+pre[j]
                elif j==now.__len__()-1:
                    now[j]=now[j]+pre[j-1]
                else:
                    now[j] = min(now[j] + pre[j - 1], now[j] +pre[j])
            pre=now[:]
        return min(now)
```