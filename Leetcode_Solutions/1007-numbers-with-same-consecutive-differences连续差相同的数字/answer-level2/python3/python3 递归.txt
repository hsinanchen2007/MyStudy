

递归不断的给数字后添加比前一个数字+K或-K的数字，当数字长度达到要求后退出递归，将其补充到结果列表中。
注意如果位数为1要把0加入到首位数字循环中


```python []
class Solution:
    def digui(self,numlist,curnum,K,L):
        if len(curnum) >= L:
            numlist.append(int(curnum))
            return True
        else:
            if int(curnum[len(curnum)-1])>=K:
                self.digui(numlist,curnum+str(int(curnum[len(curnum)-1])-K),K,L)
            if (int(curnum[len(curnum)-1])+K< 10) and (not( K == 0)):
                self.digui(numlist,curnum+str(int(curnum[len(curnum)-1])+K),K,L)
        
        
    def numsSameConsecDiff(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: List[int]
        """
        res=[]
        temp=[]
        if N == 1:
            self.digui(res,'0',K,N)
        
        for i in range(1,10):
            self.digui(res,str(i),K,N)
                     
        return res
```
