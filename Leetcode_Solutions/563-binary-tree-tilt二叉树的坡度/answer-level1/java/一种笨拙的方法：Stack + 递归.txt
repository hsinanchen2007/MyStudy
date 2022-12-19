### 解题思路
一种笨拙的方法，使用Stack存储还未计算过tilt的节点，用递归方法来计算节点的tilt以及左右子树的和。

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
    public int findTilt(TreeNode root) {
        // 判断根节点是否为空，注意到Stack不能push进null
        if( root == null)
            return 0;
        int tilt = 0;
        Stack< TreeNode > stack = new Stack();
        stack.push(root);
        while( !stack.isEmpty() ){
            TreeNode p = stack.pop();
            tilt += findNodeTilt( p );
            // Stack存储还未进行计算的节点
            if( p.left != null)
                stack.push( p.left );
            if( p.right != null )
                stack.push( p.right ); 
        }
        return tilt;
    }

    // 计算node的tilt
    public int findNodeTilt( TreeNode node ){
        if( node == null )
            return 0;
        if( node.left == null && node.right == null )
            return 0;
        if( node.left == null )
            return Math.abs( treeSum( node.right ) );
        if( node.right == null )
            return Math.abs( treeSum( node.left ) );
        return Math.abs( treeSum( node.left ) - treeSum( node.right ) );
    }

    // 计算以root为根的树的值和
    public int treeSum( TreeNode root ){
        if( root.left == null && root.right == null)
            return root.val;
        if( root.left == null )
            return root.val + treeSum( root.right );
        if( root.right == null )
            return root.val + treeSum( root.left );
        return root.val + treeSum( root.left ) + treeSum( root.right );
    }
}
```