![无标题.png](https://pic.leetcode-cn.com/b1922465a0c019f6ccb3ca0b31eee9fbe67183a7bfe413caef89ab8b5dd6e2cd-%E6%97%A0%E6%A0%87%E9%A2%98.png)

    代码应该比较清晰明了了，dfs()深度优先遍历每个节点，判断当前节点是否为偶数，若是，就使用get()获取它的隔代节点值。

```
class Solution {
    public int sumEvenGrandparent(TreeNode root) {
        return dfs(root);
    }
    
    public int dfs(TreeNode root) {
        if (root == null)
            return 0;
        if (root.val % 2 == 0)
            return get(root.left) + get(root.right) + dfs(root.left) + dfs(root.right);
        else
            return dfs(root.left) + dfs(root.right);
    }
    
    public int get(TreeNode root) {
        if (root == null)
            return 0;
        int x = (root.left == null ? 0 : root.left.val);
        int y = (root.right == null ? 0 : root.right.val);
        return x + y;
    }
}
```
