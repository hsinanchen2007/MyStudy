#### 方法 1：深度优先搜索

**想法和算法**

通过移除一些 `parent` 到 `child` 的边，（其中 `child` 不能是原始 `root`）以 `root` 为根的子树元素之和一定是整棵树和的一般。

记录每个子树的和。我们可以利用深度优先搜索递归解决。之后，检查整棵树的一半权值是否出现（但不能是整棵树之和）。

我们这种特殊的判断是为了避免以下情况的发生。

```Python [-Python]
  0
 / \
-1  1

 0
  \
   0
```

```Python []
class Solution(object):
    def checkEqualTree(self, root):
        seen = []

        def sum_(node):
            if not node: return 0
            seen.append(sum_(node.left) + sum_(node.right) + node.val)
            return seen[-1]

        total = sum_(root)
        seen.pop()
        return total / 2.0 in seen
```

```Java []
class Solution {
    Stack<Integer> seen;
    public boolean checkEqualTree(TreeNode root) {
        seen = new Stack();
        int total = sum(root);
        seen.pop();
        if (total % 2 == 0)
            for (int s: seen)
                if (s == total / 2)
                    return true;
        return false;
    }

    public int sum(TreeNode node) {
        if (node == null) return 0;
        seen.push(sum(node.left) + sum(node.right) + node.val);
        return seen.peek();
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是输入中树的节点个数。我们遍历所有的节点。
* 空间复杂度：$O(N)$，`seen` 的大小和深度优先搜索的栈开销。