### 解题思路
只需注意到一个根为root的二叉树，如果它是镜像对称的，则root.left和root.right互为镜像对称，使用递归便可。


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
    public boolean isSymmetric(TreeNode root) {
        if(root == null)
            return true;
        else
            return isTreesReflex(root.left, root.right);
    }

    public boolean isTreesReflex(TreeNode root1, TreeNode root2){
        if(root1 == null && root2 == null)
            return true;
        if(root1 == null || root2 == null)
            return false;
        if(root1.val == root2.val)
            return isTreesReflex(root1.left, root2.right) && isTreesReflex(root1.right, root2.left);
        else
            return false;
    }
}


```