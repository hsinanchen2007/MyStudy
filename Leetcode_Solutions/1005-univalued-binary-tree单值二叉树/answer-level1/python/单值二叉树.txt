#### 方法一：深度优先搜索

**思路与算法**

我们先进行一次深度优先搜索，获取这颗树中的所有节点的值。然后，就可以判断所有节点的值是不是都相等了。

```java [himT7fHE-Java]
class Solution {
    List<Integer> vals;
    public boolean isUnivalTree(TreeNode root) {
        vals = new ArrayList();
        dfs(root);
        for (int v: vals)
            if (v != vals.get(0))
                return false;
        return true;
    }

    public void dfs(TreeNode node) {
        if (node != null) {
            vals.add(node.val);
            dfs(node.left);
            dfs(node.right);
        }
    }
}
```
```python [himT7fHE-Python]
class Solution(object):
    def isUnivalTree(self, root):
        vals = []

        def dfs(node):
            if node:
                vals.append(node.val)
                dfs(node.left)
                dfs(node.right)

        dfs(root)
        return len(set(vals)) == 1
```


**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是给定树中节点的数量。

* 空间复杂度：$O(N)$。





---
#### 方法二：递归

**思路与算法**

一颗树是单值的，当且仅当根节点的子节点所在的子树也是单值的，同时根节点的值与子节点的值相同。

我们可以使用递归实现这个判断的过程。`left_correct` 表示当前节点的左孩子是正确的，也就是说：左孩子所在的子树是单值的，并且当前节点的值等于左孩子的值。`right_correct` 对当前节点的右孩子表示同样的事情。递归处理之后，当根节点的这两种属性都为真的时候，我们就可以判定这颗二叉树是单值的。

```java [5GyAMr2y-Java]
class Solution {
    public boolean isUnivalTree(TreeNode root) {
        boolean left_correct = (root.left == null ||
                (root.val == root.left.val && isUnivalTree(root.left)));
        boolean right_correct = (root.right == null ||
                (root.val == root.right.val && isUnivalTree(root.right)));
        return left_correct && right_correct;
    }
}
```
```python [5GyAMr2y-Python]
class Solution(object):
    def isUnivalTree(self, root):
        left_correct = (not root.left or root.val == root.left.val
                and self.isUnivalTree(root.left))
        right_correct = (not root.right or root.val == root.right.val
                and self.isUnivalTree(root.right))
        return left_correct and right_correct
```


**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是给定树中节点的数量。

* 空间复杂度：$O(H)$，其中 $H$ 是给定树的高度。



