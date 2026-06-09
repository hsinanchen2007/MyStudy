### 解题思路
此处撰写解题思路
用后序遍历的方式遍历二叉树的每一个结点，那么在遍历到每一个结点之前我们就已经遍历了它的左子树、右子树。只要在遍历每个结点的时候记录它的深度，并判断该节点是否平衡即可。
### 代码

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
    public boolean isBalanced(TreeNode root) {
        if(root == null)   
           return true;
        return depth(root) != -1;   
    }

    private int depth(TreeNode root){
        if(root == null)
           return 0;
        int leftDepth = depth(root.left);  //递归左子树
        if(leftDepth == -1){
            return -1;
        }  
        int rightDepth = depth(root.right); //递归右子树
        if(rightDepth == -1){
            return -1;
        } 
        //比较该节点是否满足平衡条件，若不满足，直接返回-1，若满足返回该节点的深度
        return Math.abs(leftDepth - rightDepth) > 1 ? -1 : Math.max(leftDepth , rightDepth) + 1;
    }
}

```