### 解题思路
从根节点的两个左右节点开始遍历
1，判断两个子节点是否为镜像
2，递归判断两个子节点的 左右节点 右左节点 是否为镜像
3，不满足条件 return false 即可

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
        //递归写法
        if (root == null) {
            return true;
        }
        
        return isSymmetricTree(root.left, root.right);
    }

    //递归遍历对称二叉树 判断两个节点是否为镜像
    private boolean isSymmetricTree(TreeNode left, TreeNode right) {
        
        if (left == null && right == null) {
            return true;
        } else if (left != null && right != null && left.val == right.val){//是镜像
            return isSymmetricTree(left.left, right.right) && isSymmetricTree(left.right, right.left);
        } else {
            return false;
        }
    }

}
```