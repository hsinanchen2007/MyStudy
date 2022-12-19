### 解题思路
brute force...
两个helperfunction一个放进while循环用来判断是否满足条件；另一个就是操作并储存新的列表
while判断失败时，对list进行一次action，直到list满足条件输出

### 代码

```python3
class Solution:
    def action(self,reclist:List[int])->List[int]:
        newL = []
        newL.append(reclist[0])
        for i in range(1,len(reclist)-1):
            if reclist[i]<reclist[i-1] and reclist[i]<reclist[i+1]:
                newL.append(reclist[i]+1)
            elif reclist[i]>reclist[i-1] and reclist[i]>reclist[i+1]:
                newL.append(reclist[i]-1)
            else: newL.append(reclist[i])
        newL.append(reclist[-1])
        return newL

    def judge(self,reclist):
        for i in range(1,len(reclist)-1):
            if ((reclist[i]<reclist[i-1] and reclist[i]<reclist[i+1])or
            (reclist[i]>reclist[i-1] and reclist[i]>reclist[i+1])): 
                return False
        return True

    def transformArray(self, arr: List[int]) -> List[int]:
        reclist = arr
        while not self.judge(reclist):
            reclist = self.action(reclist)
        return reclist




    
                

    
```