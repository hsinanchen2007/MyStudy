### 解题思路
 #set去重，dfs暴力深搜

### 代码

```python3
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        t=[]
        for i in arr:#去重
            if len(i)==len(set(i)):
                t.append(i)
        arrs=t[:]
   
        def dfs(i,cur):
            if i>=len(arrs):
                return len(cur)
            if not(set(cur)&set(arrs[i])):#判断集合是否相交
                #若不相交，则要判断当前arrs[i]是否要取，因为若取，可能导致后面更长的字符串和当前字符串重复而无法取
                return max(dfs(i+1,cur+arrs[i]),dfs(i+1,cur))
            else:
                return dfs(i+1,cur)
        lens=dfs(0,'')
        return lens

```