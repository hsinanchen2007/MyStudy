### 解题思路
此处撰写解题思路
for idx in range(lis):
    find(idx+1,lis[idx])=1+find(idx+2,lis[idx]) # 递归
    期间使用DP记录做过的工作：Solution.dp[nextIdx][value]=ans 尽可能多的避免重复，工作
    期间需要借助NotFound记录某个位置是否到最后都没有找到比自己大的。

### 代码

```python3
class Solution:
    dp=None
    def dailyTemperatures(self, lis: List[int]) -> List[int]:
        ans=[]
        Solution.dp=[[None]*101 for i in range(len(lis)+1)]# 100xlen(lis)
        for idx in range(len(lis)):
            NotFound=[False]
            tmp=self.find(lis,idx+1,lis[idx],NotFound)
            if NotFound[0]:
                ans.append(0)
            else:
                ans.append(tmp)
        return ans
    def find(self,lis,nextIdx,value,NotFound):
        #print('check Value %d from %d'%(value,nextIdx))
       
        if nextIdx==len(lis):
            NotFound[0]=True
            Solution.dp[nextIdx][value]=0
            return 0
        if Solution.dp[nextIdx][value]!=None:
            return Solution.dp[nextIdx][value]
        if lis[nextIdx]>value:
            Solution.dp[nextIdx][value]=1
            return 1
        ans=1+self.find(lis,nextIdx+1,value,NotFound)
        if NotFound[0]:
            Solution.dp[nextIdx][value]=0
        else:
            Solution.dp[nextIdx][value]=ans
        return ans
```