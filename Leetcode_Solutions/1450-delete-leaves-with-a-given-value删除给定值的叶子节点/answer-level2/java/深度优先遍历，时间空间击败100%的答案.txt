![100.png](https://pic.leetcode-cn.com/354fa2a1aa01fe3189353b1977c721491b340d2e7414002243cbd1aaed304b67-100.png)

思路也比较简单，就是从叶子节点递归的向上删除值为target的叶子节点

```

class Solution {
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        TreeNode dummy;
        if (target == 0) {
            dummy = new TreeNode(1);
        } else {
            dummy = new TreeNode(0);
        }
        dummy.left = root;
        boolean leaf = dfs(dummy, dummy.left, target, true);
        if (dummy.left != null && dummy.left.val == target && leaf) return null;
        return dummy.left;
    }

    // 返回值：是否是叶子节点
    private boolean dfs(TreeNode parent, TreeNode node, int target, boolean left) {
        if (node == null) return true;
        boolean ans = true;
        if (node.left != null) ans &= dfs(node, node.left, target, true);
        if (node.right != null) ans &= dfs(node, node.right, target, false);
        if (ans && node.val == target) {
            if (left) {
                parent.left = null;
            } else {
                parent.right = null;
            }
            return true;
        } else {
            return false;
        }
    }
}
```
