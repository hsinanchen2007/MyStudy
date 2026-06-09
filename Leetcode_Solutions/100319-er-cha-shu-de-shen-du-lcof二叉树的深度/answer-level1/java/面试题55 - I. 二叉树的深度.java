### 解题思路
参考剑指offer第39题题解
二叉树的深度：
  如果二叉树为一个节点 则深度为1
  如果二叉树没有左子树，则深度为1+右子树的深度
  反之相同
  如果既有左子树，也有右子树，则二叉树的深度为1+ left>right:left:right

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
    public int maxDepth(TreeNode root) {
        //二叉树的深度
        if(root==null){
            return 0;
        }
        int left=maxDepth(root.left);
        int right=maxDepth(root.right);
        return (left>right)? (left+1):(right+1);
    }
}
```