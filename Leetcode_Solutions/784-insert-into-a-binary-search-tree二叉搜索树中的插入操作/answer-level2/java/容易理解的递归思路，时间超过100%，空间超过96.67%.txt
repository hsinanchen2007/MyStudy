```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if(root == null){
            return new TreeNode(val);
        }
        return insertIntoBSTCore(root, val);
    }

    TreeNode insertIntoBSTCore(TreeNode node, int val){
        //因为题目中说了，要插入的值不存在与二叉树中，所以对于一个节点来说，只存在小于或者大于的情况
        if(node.val < val){
            //小于的时候，只能在当前节点的右侧添加，需要判断是否已经是最右节点
            if(node.right != null){
                node.right = insertIntoBSTCore(node.right, val);
            } else {
                node.right = new TreeNode(val);
            }
        } else {
            //大于的时候，只能在当前节点的左侧添加，需要判断是否已经是最左节点
            if(node.left != null){
                node.left = insertIntoBSTCore(node.left, val);
            } else {
                node.left = new TreeNode(val);
            }
        }
        return node;
    }
}
```