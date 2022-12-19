#### 方法一：深度优先搜索

我们可以使用深度优先搜索的方法解决这个问题。

我们从根节点开始进行搜索，在搜索的同时记录当前节点的深度 `dep`。我们维护两个全局变量 `maxdep` 和 `total`，其中 `maxdep` 表示搜索到的节点的最大深度，`total` 表示搜索到的深度等于 `maxdep` 的节点的权值之和。

当我们搜索到一个新的节点 `x` 时，会有以下三种情况：

- 节点 `x` 的深度 `dep` 小于 `maxdep`，那么我们可以忽略节点 `x`，继续进行搜索；

- 节点 `x` 的深度 `dep` 等于 `maxdep`，那么我们将节点 `x` 的权值添加到 `total` 中；

- 节点 `x` 的深度 `dep` 大于 `maxdep`，此时我们找到了一个深度更大的节点，因此需要将 `maxdep` 置为 `dep`，并将 `total` 置为节点 `x` 的权值。

在深度优先搜索结束之后，深度最大的叶子节点的权值之和即存储在 `total` 中。

```C++ [sol1-C++]
class Solution {
private:
    int maxdep = -1;
    int total = 0;

public:
    void dfs(TreeNode* node, int dep) {
        if (!node) {
            return;
        }
        if (dep > maxdep) {
            maxdep = dep;
            total = node->val;
        }
        else if (dep == maxdep) {
            total += node->val;
        }
        dfs(node->left, dep + 1);
        dfs(node->right, dep + 1);
    }

    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return total;
    }
};
```

```Python [sol1-Python3]
class Solution:
    def __init__(self):
        self.maxdep = -1
        self.total = 0

    def deepestLeavesSum(self, root: TreeNode) -> int:
        def dfs(node, dep):
            if not node:
                return
            if dep > self.maxdep:
                self.maxdep, self.total = dep, node.val
            elif dep == self.maxdep:
                self.total += node.val
            dfs(node.left, dep + 1)
            dfs(node.right, dep + 1)
        
        dfs(root, 0)
        return self.total
```

**复杂度分析**

- 时间复杂度：$O(N)$，其中 $N$ 是树中的节点个数。

- 空间复杂度：$O(H)$，其中 $H$ 是树的高度（最大深度）。

#### 方法二：广度优先搜索

我们同样可以使用广度优先搜索的方法解决这个问题。

除了搜索的顺序不同之外，实现的细节与深度优先搜索的方法完全相同。

```C++ [sol2-C++]
using PTI = pair<TreeNode*, int>;

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<PTI> q;
        q.emplace(root, 0);
        int maxdep = -1, total = 0;
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int dep = q.front().second;
            q.pop();
            if (dep > maxdep) {
                maxdep = dep;
                total = node->val;
            }
            else if (dep == maxdep) {
                total += node->val;
            }
            if (node->left) {
                q.emplace(node->left, dep + 1);
            }
            if (node->right) {
                q.emplace(node->right, dep + 1);
            }
        }
        return total;
    }
};
```

```Python [sol2-Python3]
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        q = collections.deque([(root, 0)])
        maxdep, total = -1, 0
        while len(q) > 0:
            node, dep = q.pop()
            if dep > maxdep:
                maxdep, total = dep, node.val
            elif dep == maxdep:
                total += node.val
            if node.left:
                q.append((node.left, dep + 1))
            if node.right:
                q.append((node.right, dep + 1))
        return total
```

**复杂度分析**

- 时间复杂度：$O(N)$，其中 $N$ 是树中的节点个数。

- 空间复杂度：$O(N)$。