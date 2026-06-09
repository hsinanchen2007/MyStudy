
```
class Solution {
    public void flatten(TreeNode root) {
        flattenHelper(root);
    }

    //递归式返回的是当前根结点，左链表或者右链表最后的尾节点（因为头节点就是root.left或root.right，只需记录尾节点即可）
    public TreeNode flattenHelper(TreeNode root) {
        // 自身为null或者无左右节点
        if (root == null || (root.left == null && root.right == null)) {
            return root;
        }

         //采用后续遍历的方式，从下往上，从左往右去变更树节点的关系
        TreeNode leftEndNode = flattenHelper(root.left);
        TreeNode rightEndNode = flattenHelper(root.right);
        if (leftEndNode != null) {
            // 此时root左右两个节点变更关系
            leftEndNode.right = root.right;
            root.right = root.left;
            root.left = null;
        }
        return rightEndNode == null ? leftEndNode : rightEndNode;
    }
}



```