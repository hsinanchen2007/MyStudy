```java
class Solution {
    private int x, y;
    private int px, py;
    private int dx, dy;
    private int num;
    public boolean isCousins(TreeNode root, int x, int y) {
        this.x = x;
        this.y = y;
        dfs(root, -1, 0);
        return dx == dy && px != py;
    }

    private void dfs(TreeNode root, int p, int d) {
        if (root == null) {
            return;
        }
        if (root.val == x) {
            px = p;
            dx = d;
            num++;
        } else if (root.val == y) {
            py = p;
            dy = d;
            num++;
        }
        if (num < 2) {
            dfs(root.left, root.val, d + 1);
            dfs(root.right, root.val, d + 1);
        }
    }
}
```
