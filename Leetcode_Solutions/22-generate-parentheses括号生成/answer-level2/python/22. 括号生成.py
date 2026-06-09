### 思路
深度优先遍历

### 代码

```python3
class Solution:
    def __init__(self):
        self.res = []

    def dfs(self, cur_res, left, right):
        # 当左右括号数量都为0，遍历搜索结束，返回当前结果
        if left == 0 and right == 0:
            self.res.append(cur_res)
        # 如果右括号数量小于左括号，则生成的结果必然无效，直接返回，无需再往深处搜索
        if right < left:
            return
        if left > 0:
            self.dfs(cur_res+'(', left-1, right)
        if right > 0:
            self.dfs(cur_res+')', left, right-1)

    def generateParenthesis(self, n: int) -> List[str]:
        self.dfs('', n, n);
        return self.res

```