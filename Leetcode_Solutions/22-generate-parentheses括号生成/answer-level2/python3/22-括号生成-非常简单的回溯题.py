### 解题思路
此处撰写解题思路
回溯题三要点
1. 结束条件：len == 2n 结束
2. 剪枝条件：当前选择，')' 比 '(' 多， 或 '(' 多于 n
3. 选择：路径更新，状态更新。

### 代码

```python3
from typing import List, Dict
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        state = { '(': 0, ')': 0 }

        def _dfs(road: List[str], state: Dict[str, int]):
            if len(road) == 2 * n:
                res.append(''.join(road))

            if state['('] < n:
                state['('] += 1
                _dfs(road + ['('], state)
                state['('] -= 1
            if state[')'] < state['(']:
                state[')'] += 1
                _dfs(road + [')'], state)
                state[')'] -= 1
    
        _dfs([], state)
        return res
```