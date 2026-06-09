### 解题思路
此处撰写解题思路
从左下角的最小二叉树开始比较，
如果左边二叉树的最深深度小于（或大于）右边二叉树且大于1
则该二叉树不是平衡二叉树。

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
        if(root==null){
            return true;
        }
        helper(root);
        return flag;
    }

    public int helper(TreeNode rot){
        if(rot==null){
            return 0;
        }
        int left = helper(rot.left);
        int right = helper(rot.right);
        if(Math.abs(left-right)>1){
            flag = false;
        }
        return Math.max(left,right)+1;
    }
}
```