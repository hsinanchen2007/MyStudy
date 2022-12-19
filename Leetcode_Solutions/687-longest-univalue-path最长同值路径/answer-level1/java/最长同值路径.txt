### 解题思路
此处撰写解题思路

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
    public int res=0;
    public int longestUnivaluePath(TreeNode root) {
        calculate(root);
        return res;
    }

    public int calculate(TreeNode root){
        if(root==null)
            return 0;
        int L=calculate(root.left);
        int R=calculate(root.right);
        int left=0, right=0;
        if(root.left!=null&&root.val==root.left.val)
            left=L+1;
        if(root.right!=null&&root.val==root.right.val)
            right=R+1;
        res=Math.max(res,right+left);
        return Math.max(left,right);
    }
}
```