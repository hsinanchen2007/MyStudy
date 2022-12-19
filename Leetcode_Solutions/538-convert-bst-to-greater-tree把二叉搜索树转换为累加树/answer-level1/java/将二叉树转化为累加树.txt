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
    int sum=0;  //保存累加的值,是遍历到当前节点之前累加的值
    public TreeNode convertBST(TreeNode root) {
        //二叉树遍历为right,node,left
        //递归的条件——空树
        if(root==null)
            return null;
        //遍历右子树
        convertBST(root.right);
        //遍历根节点
        root.val=root.val+sum;
        sum=root.val;
        convertBST(root.left);
        return root;
    }
}
```