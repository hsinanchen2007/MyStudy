### 递归
递归遍历每个结点，判断以每个结点为根的子树是否为单值二叉树：
若当前结点值等于原树根结点值，且左子树也是单值二叉树，右子树也是单值二叉树，则当前树为单值二叉树，向上返回当前树的结果。

代码：
```java
class Solution {
    private int r;
    public boolean isUnivalTree(TreeNode root) {
        r = root.val;
        return dfs(root);
    }
    private boolean dfs(TreeNode root) {//递归遍历每棵子树并判断每棵子树是否为单值二叉树
        if(root == null)    return true;
        return (root.val == r) && dfs(root.left) && dfs(root.right);
    }
}
```

### 迭代
层序遍历，逐个结点与根结点值作比较，一旦不相同，即返回false。

代码：
```java
class Solution {
    public boolean isUnivalTree(TreeNode root) {
        int r = root.val;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty())
        {
            TreeNode cur = q.poll();
            if(cur.val != r)        return false;
            if(cur.left != null)    q.offer(cur.left);
            if(cur.right != null)   q.offer(cur.right);
        }
        return true;
    }
}
```