### 解题思路
此处撰写解题思路
遍历顺序为后序遍历
首先遍历最左边的最小左子树
计算最小左子树的左长度和右长度，取其中最大值
之后依次回溯，依次计算树的左长度和右长度，取其中最大值，
若中途有左长度与右长度之差大于1，则不是平衡二叉树
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
   boolean flag = true;
    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }
        int left = helper(root.left);
        int right = helper(root.right);
        if(Math.abs(left-right)>1){
            return false;
        }
        return flag;
    }

    public int helper(TreeNode root){
        if(root==null){
            return 0;
        }
        int left = helper(root.left);
        int right = helper(root.right);
        if(Math.abs(left-right)>1){
            flag = false;
        }
        return Math.max(left,right)+1;
    }
}
```