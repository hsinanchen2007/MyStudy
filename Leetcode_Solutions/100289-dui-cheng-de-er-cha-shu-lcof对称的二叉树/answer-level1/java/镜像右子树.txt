### 解题思路
右子树镜像，对比左右子树是否相等

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
        if (root == null) return true;
        return isSame(root.left,mirrorTree(root.right));
    }


    public boolean isSame(TreeNode node1,TreeNode node2){
        if (node1 == null && node2 == null) {
            return true;
        }
        if (node1 == null) {
            return false;
        }
        if (node2 == null) {
            return false;
        }
        if (node1.val != node2.val) {
            return false;
        }
        return isSame(node1.left,node2.left)&&isSame(node1.right,node2.right);
    }

    public TreeNode mirrorTree(TreeNode root){
        if (root == null) {
            return null;
        }
        TreeNode tempNode = mirrorTree(root.left);
        root.left = mirrorTree(root.right);
        root.right = tempNode;
        return root;
    }


}
```