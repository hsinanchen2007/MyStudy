#### 方法一： 两次深度优先搜索

**思路**

最直白的做法，先做一次深度优先搜索标记所有节点的深度来找到最深的节点，再做一次深度优先搜索用回溯法找最小子树。定义第二次深度优先搜索方法为 `answer(node)`，每次递归有以下四种情况需要处理：

* 如果 `node` 没有左右子树，返回 `node`。 

* 如果 `node` 左右子树的后代中都有最深节点，返回 `node`。

* 如果只有左子树或右子树中有且拥有所有的最深节点，返回这棵子树的根节点（即 `node` 的左/右孩子）。

* 否则，当前子树中不存在答案。

**算法**

先做一次深度优先搜索标记所有节点的深度，再做一次深度优先搜索找到最终答案。

```java [solution1-Java]
class Solution {
    Map<TreeNode, Integer> depth;
    int max_depth;
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        depth = new HashMap();
        depth.put(null, -1);
        dfs(root, null);
        max_depth = -1;
        for (Integer d: depth.values())
            max_depth = Math.max(max_depth, d);

        return answer(root);
    }

    public void dfs(TreeNode node, TreeNode parent) {
        if (node != null) {
            depth.put(node, depth.get(parent) + 1);
            dfs(node.left, node);
            dfs(node.right, node);
        }
    }

    public TreeNode answer(TreeNode node) {
        if (node == null || depth.get(node) == max_depth)
            return node;
        TreeNode L = answer(node.left),
                 R = answer(node.right);
        if (L != null && R != null) return node;
        if (L != null) return L;
        if (R != null) return R;
        return null;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def subtreeWithAllDeepest(self, root):
        # Tag each node with it's depth.
        depth = {None: -1}
        def dfs(node, parent = None):
            if node:
                depth[node] = depth[parent] + 1
                dfs(node.left, node)
                dfs(node.right, node)
        dfs(root)

        max_depth = max(depth.itervalues())

        def answer(node):
            # Return the answer for the subtree at node.
            if not node or depth.get(node, None) == max_depth:
                return node
            L, R = answer(node.left), answer(node.right)
            return node if L and R else L or R

        return answer(root)
```


**复杂度分析**

* 时间复杂度： $O(N)$，其中 $N$ 为树的大小。

* 空间复杂度： $O(N)$。

#### 方法二： 一次深度优先搜索

**思路**

可以把 **方法一** 中两次深度优先搜索合并成一次，定义方法 `dfs(node)`，与方法一中不同的是 `dfs(node)` 返回两个值，子树中的答案和 `node` 节点到最深节点的距离。

**算法**

`dfs(node)` 返回的结果有两个部分：
* `Result.node`：包含所有最深节点的最小子树的根节点。 
* `Result.dist`：`node` 到最深节点的距离。

分别计算 `dfs(node)` 的两个返回结果：

* 对于 `Result.node`：

    * 如果只有一个 `childResult` 具有最深节点，返回 `childResult.node`。

    * 如果两个孩子都有最深节点，返回 `node`。

* `Result.dist` 为 `childResult.dist` 加 `1`。

```java [solution2-Java]
class Solution {
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        return dfs(root).node;
    }

    // Return the result of the subtree at this node.
    public Result dfs(TreeNode node) {
        if (node == null) return new Result(null, 0);
        Result L = dfs(node.left),
               R = dfs(node.right);
        if (L.dist > R.dist) return new Result(L.node, L.dist + 1);
        if (L.dist < R.dist) return new Result(R.node, R.dist + 1);
        return new Result(node, L.dist + 1);
    }
}

/**
 * The result of a subtree is:
 *       Result.node: the largest depth node that is equal to or
 *                    an ancestor of all the deepest nodes of this subtree.
 *       Result.dist: the number of nodes in the path from the root
 *                    of this subtree, to the deepest node in this subtree.
 */
class Result {
    TreeNode node;
    int dist;
    Result(TreeNode n, int d) {
        node = n;
        dist = d;
    }
}
```

```python [solution2-Python]
class Solution(object):
    def subtreeWithAllDeepest(self, root):
        # The result of a subtree is:
        # Result.node: the largest depth node that is equal to or
        #              an ancestor of all the deepest nodes of this subtree.
        # Result.dist: the number of nodes in the path from the root
        #              of this subtree, to the deepest node in this subtree.
        Result = collections.namedtuple("Result", ("node", "dist"))
        def dfs(node):
            # Return the result of the subtree at this node.
            if not node: return Result(None, 0)
            L, R = dfs(node.left), dfs(node.right)
            if L.dist > R.dist: return Result(L.node, L.dist + 1)
            if L.dist < R.dist: return Result(R.node, R.dist + 1)
            return Result(node, L.dist + 1)

        return dfs(root).node
```


**复杂度分析**

* 时间复杂度： $O(N)$，其中 $N$ 为树的大小。

* 空间复杂度： $O(N)$。