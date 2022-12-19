### 代码
```python
class Solution(object):
    def combinationSum2(self, candidates, target):
        self.ans = []
        temp = []
        self.combination(candidates,target,temp,0)
        #排序 去重
        for i in range(len(self.ans)):
            self.ans[i].sort()
        self.ans = list(set(map(tuple,self.ans)))
        for i in range(len(self.ans)):
            self.ans[i] = list(self.ans[i])
        return self.ans

    def combination(self,candidates,target,temp,start):
        #终止条件
        if target == 0:
            self.ans.append(temp[:])
        for i in range(start,len(candidates)):
            res = target - candidates[i]
            if res < 0:continue
            temp.append(candidates[i])
            self.combination(candidates,res,temp,i+1)
            temp.pop()
```
