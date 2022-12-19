### 解题思路
跟100一样，100是判断两颗树是否一样，此题判断一个树是否是镜像，可以先判断根节点，然后将树分成两颗，利用100题的方法判断是否
是对称二叉树。

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
        if(root == null) return true;
        return  isSameTree(root.left, root.right);
    }
    public boolean isSameTree(TreeNode left, TreeNode right){
        if(left == null && right == null) return true;
        if(left == null || right == null) return false;
        if(left.val == right.val){
            return isSameTree(left.left,right.right) && isSameTree(left.right,right.left);
        }else{
            return false;
        }
    }
}
```