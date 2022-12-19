### 解题思路
设置一个 begin 变量来控制开始枚举的范围，重复数字不要枚举。




### 代码

```python3
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def dfs(tmp, begin):  #设置一个 begin 指针
            if len(tmp) == k:
                res.append(tmp)
                return
            for i in range(begin, n+1):  # n+1
                dfs(tmp+[i], i+1)
        if k>n:
            return []
        res = []
        dfs([], 1)
        return res

```