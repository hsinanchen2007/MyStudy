### 解题思路
如果树只有一个节点，那么深度就是1；
如果树只有左子树，没有右子树，那么深度就为左子树的深度加一；
如果树只有右子树，没有左子树，那么深度就为右子树的深度加一；
如果树既有左子树又有右子树，那么树的深度就是左，右子树的较大值加一；

基于以上思想可以把问题分解成求左子树最深值加右子树最深值即树的为直径。

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
    public int maxDepth = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        if(root==null)return 0;
        depth(root);
		return maxDepth;
    }

    public int depth(TreeNode root){
        if(root==null)return 0;
        int nLeft = depth(root.left);
		int	nRight = depth(root.right);
		maxDepth = maxDepth>(nLeft + nRight)?maxDepth:(nLeft + nRight);
		return (nLeft>nRight)?nLeft+1:nRight+1;
    }
}