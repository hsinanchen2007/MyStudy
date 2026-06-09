### 解题思路
🐸跳跃的终止条件为以下两种：
1. 时间花光时，如果当前结点 $u$ 恰好为 $target$，概率为 $p$，否则为 $0$;
2. 时间没用完，但是跳到了叶子结点，如果当前叶子结点 $u$ 恰好为 $target$，概率为 $p$，否则为 $0$。

$$ t=0\left\{
\begin{aligned}
u = target & , & p &      \\
u  ≠ target & , & 0 \\
\end{aligned}
\right.
$$

$$ t>0\left\{
\begin{aligned}
u = target & , & p  \\
u  ≠ target & , & 0 \\
\end{aligned}
\right.
$$

因此我们只需深度优先遍历这棵树，分条件讨论概率即可。

本题和上一题有一个共同点，即输入并不是一棵树，因此我们需要处理输入进行处理。一般不需要重新建树，存储树形关系可以有以下两种方式：
- 使用邻接矩阵
- 使用二维数组

我们使用二维数组保存结点（这是保存树形关系的一个常用方法），注意深度优先搜索时，如果碰到父结点就避开。

### 代码

```cpp []
class Solution {
public:
    vector<vector<int>> e;
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        e = vector<vector<int>> (n + 1); // 下标从 1 开始
        for (auto edge : edges){
            int a = edge[0], b = edge[1];
            e[a].push_back(b);
            e[b].push_back(a);
        }

        return dfs(1, -1, t, target, 1);
    }

    double dfs(int u, int father, int t, int target, double p){
        /*
        u: 当前结点； father：避免遍历到父节点；t：剩余时间；p:当前概率
        */
        if (t == 0){
            if (u == target) return p;
            return 0;
        }

        int k = e[u].size(); // 当前结点u的孩子个数
        if (u != 1) k --; // 除了根节点1，孩子个数需要减去父节点的那条边

        if (k == 0){ // 到达叶子结点
            if (u == target) return p;
            return 0;
        }

        double res = 0;
        for (auto s: e[u]){
            if (s != father)
                res = max(res, dfs(s, u, t - 1, target, p * 1.0 / k));
        }
        return res;

    }
};
```
```python []
class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        self.e = [[]for _ in range(n + 1)] # 下标从 1 开始
        for edge in edges: # 存结点
            a = edge[0]
            b = edge[1]
            self.e[a].append(b)
            self.e[b].append(a)
        return self.dfs (1, -1, t, target, 1)

    def dfs(self, u, father, t, target, p):
        """u: 当前结点； father：避免遍历到父节点；t：剩余时间；p:当前概率"""
        if t == 0:
            if u == target: return p
            return 0
        k = len(self.e[u]) # 当前结点u的孩子个数
        if u != 1: k -= 1  # 除了根节点1，孩子个数需要减去父节点的那条边
        if k == 0:  # 到达叶子结点
            if u == target: return p
            return 0
        
        res = 0
        for s in self.e[u]:
            if s != father:
                res = max(res, self.dfs(s, u, t - 1, target, p * 1.0 / k))
        return res
```
### 复杂度分析
- 时间复杂度：$O(n)$，遍历了每一个结点。
- 空间复杂度：$O(n)$，使用了数组存储每一个结点。