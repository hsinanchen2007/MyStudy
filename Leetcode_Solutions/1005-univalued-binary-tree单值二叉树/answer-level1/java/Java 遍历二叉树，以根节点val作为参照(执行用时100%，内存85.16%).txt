```
    int val;
    boolean result = true;
    public boolean isUnivalTree(TreeNode root) {
        val = root.val;
        dfs(root);
        return result;
    }
    public void dfs(TreeNode node){
        //如果result为false或节点为空直接返回
        if (!result || node == null){
            return;
        }
        //与根节点值不同，result为false
        if (node.val != val){
            result = false;
            return;
        }
        dfs(node.left);
        dfs(node.right);
    }
```
