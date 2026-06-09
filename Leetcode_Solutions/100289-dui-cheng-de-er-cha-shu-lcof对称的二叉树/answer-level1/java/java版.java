### 解题思路
镜像二叉树有以下特征：
1二叉树左子树的右孩子的值等于右子树的左孩子的值。
2 二叉树左子树的左孩子的值等右子树的右孩子的值。
3 根据以上两个特征递归遍历二叉树的每个节点左右子树的情况。

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
        if(root==null) return true;
        return isSym(root.left,root.right);

    }
    public boolean isSym(TreeNode l,TreeNode r){
        if(l==null&&r==null) return true;
        if(l==null||r==null) return false;
        if(l.val!=r.val) return false;
        return isSym(l.right,r.left)&&isSym(l.left,r.right);
    }
}
```