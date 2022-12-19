## 思路分析
构建二叉树，即构建子树的根节点，左右孩子节点，子子树的根节点与左右孩子节点.....，由此可见可以采用分治法思想，递归实现。

本题是从前序和中序中构建二叉树，由前序和中序的特性，如题描述：
```
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
```
那么构建过程如下：
1. 当子树的根节点为3（preorder = [3]）， 左子树中序序列 [9], 右子树中序序列 [15, 20, 7]；
2. 再构建节点3的左子树，当根节点为9（preorder = [3, 9]），当前子树的左右子树够建完毕；
3. 再构建节点3的右子数，当节点为20（preorder = [3, 9, 20]），本子树的左子树序列 [15]，右子树序列[7], 递归构建相应的子树;

思路的关键点：
-  确定各子树的节点值在 inorder中的下标范围;
-  构建树的过程中遍历preorder, 需要记录其遍历下标；


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
    
    private int preIndex = 0;
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder.length != inorder.length)
            throw new IllegalArgumentException("please check params");
        if(preorder.length==0) return null;
        return buildTree(preorder, inorder, 0, inorder.length-1);
    }
    
    public TreeNode buildTree(int[] preorder, int[] inorder,  int left, int right) {
        // 节点遍历完毕
        if(preIndex>preorder.length-1) return null;
        //  当前子树没有左或右孩子
        if( left>right) return null;
        
        // 构造子树的root节点
        TreeNode node = new TreeNode(preorder[preIndex++]);
        Integer cut = null;
        for(int i=left; i<=right; i++){
            if(inorder[i]==node.val){
                cut = i;
                break;
            } 
        }
        if(cut==null) return null;
        
        node.left = buildTree(preorder, inorder, left, cut-1);
        node.right =  buildTree(preorder, inorder, cut+1, right);
        return node;
    }
}
```