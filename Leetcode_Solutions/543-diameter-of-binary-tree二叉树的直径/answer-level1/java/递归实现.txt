### 解题思路
要求的最大直径可能有3种位置，
1.包括root结点
2.在root的左子树中
3.在root的右子树中
很容易想到要递归地求root、left树、right树的最大直径，具体到求root的最大直径，
转化为求其左子树的最大深度+1 加上 其右子树的最大深度+1。
那么如何求这两个子树的最大深度，递归地求树的深度啊！
时间复杂度O(n^2)
空间复杂度O(n)
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

    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null)
            return 0;
        int rootDiameter = findNodeEdges(root);
        int leftDiameter = diameterOfBinaryTree(root.left);
        int rightDiameter = diameterOfBinaryTree(root.right);
        return Math.max(rootDiameter,Math.max(leftDiameter,rightDiameter));

    }

    private int findNodeEdges(TreeNode node){
        if(node == null)
            return 0;
        int left = 0;
        int right = 0;

        if(node.left != null)
            left = findChildEdges(node.left, 1);
        if(node.right != null)
            right = findChildEdges(node.right,1);
        return left + right;   
    }

    private int findChildEdges(TreeNode node, int edges){
        if(node == null)
            return edges;
        if(node.left == null && node.right == null)
            return edges;
        int left = 0;
        int right = 0;
        if(node.left != null)
            left = findChildEdges(node.left, edges+1);
        if(node.right != null)
            right = findChildEdges(node.right, edges+1);
        return left >= right ? left : right;
    }
}
```