### 解题思路
组合问题的dfs问题，模板如下
arr是需要组合的元素，m为组合的个数，res用来保存结果，tmp用来保存一个路径的结果,cur为当前遍历的节点
```
def group(arr, m, res, tmp, cur):
    if len(tmp) == m:
        res.append(tmp.copy())
    for i in range(cur, len(arr)):
        res.append(arr[i])
        group(arr, m, res, tmp, i+1)
        res.pop()
```

### 代码

```python3
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        def dfs(res, tmp, n, k, cur):
            if n < 0 or k < 0:#剪枝，消除不必要的路径搜索
                return 
            if n == 0 and k == 0:#递归终止条件，保存结果
                res.append(tmp.copy())
                return
            for i in range(cur, 10):#继续搜索子节点
                tmp.append(i)
                dfs(res, tmp, n-i, k-1, i+1)
                tmp.pop()
        dfs(res, [], n, k, 1)
        return res
```