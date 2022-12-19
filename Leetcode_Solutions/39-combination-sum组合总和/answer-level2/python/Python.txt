### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def combinationSum(self, candidates, target):
        ans=[]
        def dfs(temp,start,target):
            if target==0:
                ans.append(temp)
                return
            if start>len(candidates)-1:
                return
            elif target>0:
                for i in range(start,len(candidates)):
                    # temp.append(i)
                    dfs(temp+[candidates[i]],i,target-candidates[i])
            else:
                return
        if len(candidates)==0:
            return []
        candidates.sort()
        temp=[]
        dfs([],0,target)
        #ans.append(temp)
        #print(candidates)
        return ans
```