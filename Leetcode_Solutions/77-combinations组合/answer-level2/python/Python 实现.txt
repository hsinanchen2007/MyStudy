


```
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res=[]  #存最终答案的list
        lres=[] #存每个组合的list
        i=1 #表示第i个数，也就是数字i本身，开始是1
        def comb(lres,i,k):
            if i>n :
                return
            lres=lres+[i]        #加数字到小组合lres里
            if k==1:             #判定组合是否满足要求的长度，如满足存到res里
                res.append(lres)
            comb(lres, res,i+1, k-1)    #选择某数,则K减1
            lres=lres[:-1]              #回溯
            comb(lres,i+1, k)      #不选某数，k不变
        comb(lres,i,k)
        return res
```
