### 解题思路
将根节点的左右子树看做两个二叉树进行比较

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
        if(root == null ){
            return true;
        }

        return compare(root.left,root.right);
    }

    public boolean compare(TreeNode root1,TreeNode root2){

        if(root1 == null && root2 == null){
            return true;
        }
        if(root1 == null || root2 == null){
            return false;
        }
        if(root1.val == root2.val){
            return compare(root1.left,root2.right)&compare(root1.right,root2.left);
        }
        return false;


    }
}
```