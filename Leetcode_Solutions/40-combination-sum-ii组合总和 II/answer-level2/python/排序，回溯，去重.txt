### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        
         
        self.res=[]
        candidates.sort()
        def dfs(candidates,path):
            if sum(path)>target:
                return 
            if sum(path)==target and path not in self.res:
                self.res.append(path[:])
            for i in range(len(candidates)):
                if candidates[i]>target:
                    continue
                path.append(candidates[i])
                dfs(candidates[i+1:],path)
                path.remove(candidates[i])
        dfs(candidates,[])
       


        return self.res
```