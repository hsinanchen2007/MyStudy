可以写递归，这个最好写，而且代码还简单，不过需要注意一些细节。

```
class Solution {
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        return (root ==null) ? null : DFS(null, root);
    }
    public TreeNode DFS (TreeNode parent, TreeNode node) {
        TreeNode temp = (node.left == null) ? node : DFS (node, node.left);        
        node.left = (parent == null) ? null : parent.right;
        node.right = parent;
        return temp;
    }
}
```

当然如果你想， 也可以写成循环，就是比较蛋疼，当然，莽就完事儿了。

```
class Solution {
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        TreeNode temp_left = null;
        TreeNode temp_right = null;
        TreeNode exParent = null;
        TreeNode exParent_right = null;
        while (root != null) {
            temp_left = root.left;
            temp_right = root.right;
            root.right = exParent;
            root.left = exParent_right;
            exParent = root;
            root = temp_left;            
            exParent_right = temp_right;
        }
        return exParent;
    }
}
```
