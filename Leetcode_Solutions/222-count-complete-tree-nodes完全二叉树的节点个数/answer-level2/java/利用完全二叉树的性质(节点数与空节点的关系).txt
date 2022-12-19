
**完全二叉树节点的个数为完全二叉树中所有空节点个数减一**

```
class Solution {
    public int countNodes(TreeNode root) {
        // 完全二叉树节点的个数 = 完全二叉树中所有空节点个数 - 1
        return countNullNodes(root) - 1;
    }
    
    /**
     *  计算空节点的个数
     *
     */
    private int countNullNodes(TreeNode root) {
        if (root == null)
            return 1;
        
        return countNullNodes(root.left) + countNullNodes(root.right);
    }
}
```
