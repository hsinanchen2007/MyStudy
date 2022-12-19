观察题目可以简单的发现，这就是一个前序遍历，我们需要做的就是在前序遍历时，将节点依次放入根的右子树中。


```
class Solution {
    //记录父节点
    TreeNode lastNode;
    //以root为根的前序遍历，将root放入父节点右子树中。
    public void flatten(TreeNode root) {
        if(root == null) return;
        if(lastNode != null){
            lastNode.left = null;
            lastNode.right = root;
        }
        lastNode = root;
        TreeNode right = root.right;
        flatten(root.left);
        flatten(right);
    }
}
```
