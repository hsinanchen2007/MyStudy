![image.png](https://pic.leetcode-cn.com/22db3b5892930ca8762a3491254bc9c0b6a62b3de30b768b8cfa7d18ba844f74-image.png)

使用递归遍历树，用两个数组保存

```
    int[] depth = new int[2];
    TreeNode[] node = new TreeNode[2];
    public boolean isCousins(TreeNode root, int x, int y) {
        helper(root, x, y, 0);
        if(depth[0] == depth[1] && node[0] != node[1]) {
            return true;
        }
        return false;
    }
    public void helper(TreeNode root, int x, int y, int d) {
        if(root == null) {
            return;
        }
        d++;
        if(root.left != null && root.left.val == x || root.right != null && root.right.val == x) {
            depth[0] = d;
            node[0] = root;
        }
        if(root.left != null && root.left.val == y || root.right != null && root.right.val == y) {
            depth[1] = d;
            node[1] = root;
        }
        helper(root.left, x, y, d);
        helper(root.right, x, y, d);
    }
```
