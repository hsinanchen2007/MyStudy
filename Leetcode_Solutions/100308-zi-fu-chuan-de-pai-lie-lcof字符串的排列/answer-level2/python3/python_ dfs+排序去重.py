这道题本质上是全排列，所以我们用dfs即可，并且每一步都会在dfs的参数里面记录还可以搜索的范围和已经经过的路径。直到根节点再统计。
重复值可以用排序的方法来解决，排序好之后，在展开一个分支去搜索之前，若发现和前一个完全一样，则跳过
```python
class Solution:
    def permutation(self, s: str) -> List[str]:
        #思路：dfs同时记录路径，到根节点处统计结果
        s = sorted(list(s))

        res = []
        def dfs(s,road):
            if s == []:
                res.append(''.join(road))
            for i in range(len(s)):
                if i>0 and s[i] == s[i-1]:continue 
                dfs(s[:i]+s[i+1:], road+[s[i]])
        dfs(s,[])
        return(res)



```