考虑删的节点的几种不同情况
```
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        TreeNode parent = root;
        TreeNode node = root; // 记录找到的节点
        while (node != null) {
            if (key == node.val) { // 找到了
                break;
            }
            parent = node;
            node = key > node.val ? node.right : node.left;
        }
        if (node == null) { // 没找到删除的值
            return root;
        }

        if (node.left == null && node.right == null) { // 找到的是叶节点
            if (node == root) { // 只有一个根节点的情况
                return null;
            }
            if (parent.left == node) {
                parent.left = null;
            } else {
                parent.right = null;
            }
        } else if (node.left != null && node.right == null) { // 只有左子树的情况
            if (node == root) { // 根节点特殊处理
                return node.left;
            }
            if (parent.left == node) {
                parent.left = node.left;
            } else {
                parent.right = node.left;
            }
            node.left = null;
        } else if (node.left == null && node.right != null) { // 只有右子树的情况
            if (node == root) { // 根节点特殊处理
                return node.right;
            }
            if (parent.left == node) {
                parent.left = node.right;
            } else {
                parent.right = node.right;
            }
            node.right = null;
        } else { // 左右子树的情况，找右子树中最小的节点替换即可
            TreeNode target = node;
            parent = node;
            node = node.right;
            while (node.left != null) { // 看看是否有左子树
                parent = node;
                node = node.left;
            }
            target.val = node.val;
            if (parent.left == node) {
                parent.left = node.right;
            } else {
                parent.right = node.right;
            }
            node.right = null;
        }
        return root;
    }
}
```