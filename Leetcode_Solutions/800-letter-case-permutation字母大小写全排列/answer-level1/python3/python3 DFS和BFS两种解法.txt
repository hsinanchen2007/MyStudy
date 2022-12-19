一、DFS
递归方式实现。中间结果通过temp变量实现值传递；递归结束条件是指针i走到字符串S末尾，此时将结果temp添加到最终的res数组中即可。

```python3
class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        if not S:
            return ['']
        self.res=[]
        self.dfs(S,0,'')
        return self.res

    def dfs(self,S,i,temp):
        if i==len(S):
            self.res.append(temp)
            return 
        if S[i].isdigit():
            self.dfs(S,i+1,temp+S[i])
        else:
            self.dfs(S,i+1,temp+S[i].lower())
            self.dfs(S,i+1,temp+S[i].upper())
```
二、BFS
迭代方式实现。通过从左至右线性扫描字符串S，并将当前的所有可能结果更新到数组res中即可。

```python3
class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        res=['']
        for i,c in enumerate(S):
            if c.isdigit():
                for j,r in enumerate(res):
                    res[j]=r+c
            else:
                temp=[]
                for r in res:
                    temp.append(r+c.lower())
                    temp.append(r+c.upper())
                res=temp[:]
        return res
```