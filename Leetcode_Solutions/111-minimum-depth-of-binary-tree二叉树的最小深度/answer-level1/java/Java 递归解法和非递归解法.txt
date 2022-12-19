递归解法
```java
class Solution {
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null) return 1 + minDepth(root.right);
        if (root.right == null) return 1 + minDepth(root.left);
        return 1 + Math.min(minDepth(root.left), minDepth(root.right));
    }
}
```

非递归解法

```java
class Solution2 {
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int level = 0;
        while (!q.isEmpty()) {
            level ++;
            for (int i = q.size(); i > 0; i --) {
                TreeNode top = q.poll();
                if (top.left == null && top.right == null) return level;
                if (top.left != null) q.add(top.left);
                if (top.right != null) q.add(top.right);
            }

            
        }
        return 0;
    }
}
```