#### 方法：标记父节点与深度

**思路**

当且仅当一对节点深度相同而父节点不相同时，它们是堂兄弟节点。一种非常直接的方法就是通过某种方法求出每一个节点的深度与父节点。

**算法**

我们用深度优先搜索标记每一个节点，对于每一个节点 `node`，它的父亲为 `par`，深度为 `d`，我们将其记录到 `Hashmap` 中：`parent[node.val] = par` 且 `depth[node.val] = d`。


```java [YSAzV8YK-Java]
class Solution {
    Map<Integer, Integer> depth;
    Map<Integer, TreeNode> parent;

    public boolean isCousins(TreeNode root, int x, int y) {
        depth = new HashMap();
        parent = new HashMap();
        dfs(root, null);
        return (depth.get(x) == depth.get(y) && parent.get(x) != parent.get(y));
    }

    public void dfs(TreeNode node, TreeNode par) {
        if (node != null) {
            depth.put(node.val, par != null ? 1 + depth.get(par.val) : 0);
            parent.put(node.val, par);
            dfs(node.left, node);
            dfs(node.right, node);
        }
    }
}
```
```python [YSAzV8YK-Python]
class Solution(object):
    def isCousins(self, root, x, y):
        parent = {}
        depth = {}
        def dfs(node, par = None):
            if node:
                depth[node.val] = 1 + depth[par.val] if par else 0
                parent[node.val] = par
                dfs(node.left, node)
                dfs(node.right, node)

        dfs(root)
        return depth[x] == depth[y] and parent[x] != parent[y]
```


**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是给定树中节点的数量。

* 空间复杂度：$O(N)$。



