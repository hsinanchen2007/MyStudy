### 解题思路
二叉搜索树的递归操作，常见问题。
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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        //遇到二叉树的问题不用往深想，递归就可以了
        if(root==null)
            return new TreeNode(val);
        if(root.val<val)
            root.right=insertIntoBST(root.right,val);  //向右侧插入
        if(root.val>val)
            root.left=insertIntoBST(root.left,val);   //向左侧插入
        return root;
    }
}
```