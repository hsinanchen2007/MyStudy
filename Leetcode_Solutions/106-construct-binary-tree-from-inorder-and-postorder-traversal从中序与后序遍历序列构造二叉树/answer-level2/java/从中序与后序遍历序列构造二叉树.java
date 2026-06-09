
> 同 [105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)思路一致，区别在于先构建子树的右子树，在构建其左子树；

## 代码实现
```java
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
    
    private int postIndex = 0;
    
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(postorder.length != inorder.length)
            throw new IllegalArgumentException("please check params");
        if(postorder.length==0) return null;
        postIndex = postorder.length-1;
        return buildTree(postorder, inorder, 0, inorder.length-1);
    }
    
    public TreeNode buildTree(int[] postorder, int[] inorder,  int left, int right) {
        // 节点遍历完毕
        if(postIndex<0) return null;
        //  当前子树没有左或右孩子
        if( left>right) return null;
        
        // 构造子树的root节点
        TreeNode node = new TreeNode(postorder[postIndex--]);
        Integer cut = null;
        for(int i=left; i<=right; i++){
            if(inorder[i]==node.val){
                cut = i;
                break;
            } 
        }
        if(cut==null) return null;
        
        node.right =  buildTree(postorder, inorder, cut+1, right);
        node.left = buildTree(postorder, inorder, left, cut-1);
        return node;
    }
}
```