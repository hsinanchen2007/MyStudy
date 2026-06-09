### 思路

**回溯**

```
回溯三步骤
1.有效结果：path 长度等于 k。
2.回溯范围及答案更新。
3.剪枝条件：经过分析，可以发现 i 应该 <= n - (k - len(path)) + 1。
详细分析可以参考 liweiwei1419 的题解（在最后）。
```

##### Python3代码

```python
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        # special judgment
        if n <= 0 or k <= 0 or k > n:
            return []
        
        res = []
        self.dfs(1, k, n, [], res)
        return res
    
    def dfs(self, start, k, n, path, res):
        # 1.valid result
        if len(path) == k:
            res.append(path[:])
            return
        
        # 3.pruning
        for i in range(start, n - (k - len(path)) + 2):
            # 2.backtrack and update
            path.append(i)
            self.dfs(i + 1, k, n, path, res)
            path.pop()
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/0077-Combinations/0077.py)

### 参考

[liweiwei1419 题解](https://leetcode-cn.com/problems/combinations/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-ma-/)