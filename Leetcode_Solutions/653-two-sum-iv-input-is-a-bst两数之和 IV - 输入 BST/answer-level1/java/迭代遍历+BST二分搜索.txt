相比烧脑的数组二分搜索，BST上的二分搜索简直太舒服了。
遍历如果用递归的话无法中途break，我觉得是因为调用栈不是自己维护所以只能一层层返回，于是用stack实现迭代版的dfs。
```java
class Solution {
    private boolean search(TreeNode root, TreeNode cur, int y) {
        // binary seach on a BST(root), find node.val == y && node != cur
        while (root != null) {
            if (root.val == y && root != cur) {
                return true;
            } else if (y < root.val) {
                root = root.left;
            } else {
                root = root.right;
            }
        }
        return false;
    }
    
    public boolean findTarget(TreeNode root, int k) {
        if (root == null) return false;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode cur = stack.pop();
            boolean result = search(root, cur, k - cur.val); // cur.val is x, we are here to find y
            if (result) return true;
            if (cur.left != null) stack.push(cur.left);
            if (cur.right != null) stack.push(cur.right);
        }
        return false;
    }
}
```
