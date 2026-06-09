```
class Solution:
    def minSwap(self, A: List[int], B: List[int]) -> int:
        n = len(A)
        huan = 1
        buhuan = 0
        for i in range(1,n):
            if A[i]>A[i-1] and B[i]>B[i-1]:#本来就不用换
                if A[i]>B[i-1] and B[i]>A[i-1]:#换了也满足
                    huan = min(huan,buhuan)+1#那么i次换就是i-1次的小值加1次
                    buhuan = huan-1
                else:#换了前面的也要跟着换
                    huan += 1
            else:#本来需要换
                t = buhuan
                buhuan = huan#如果i不换那么交换前面的
                huan = t+1
        return min(huan,buhuan)
```
