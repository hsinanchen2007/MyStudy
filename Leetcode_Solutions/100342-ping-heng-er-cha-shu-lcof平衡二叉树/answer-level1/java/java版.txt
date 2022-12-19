### 解题思路
1设置标志位，用于标记左右子树的高度差是否小于1.
2 设置求左右子树高度的函数，递归求左右子树的高度差是否小于1。
3如果一棵树为平衡二叉树，那么这棵树的左右子树必然是平衡二叉树。
4如果高度差小于1则说明以某个节点为头节点的二叉树为平衡二叉树，此时标志位不变。
5 否则改变标志位，说明该二叉树不是平衡二叉树。

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
     boolean flag=true;
    public boolean isBalanced(TreeNode root) {
        if(root==null) return true;
        height(root);
        return flag;
    }
    public int height(TreeNode root){
        if(root==null){
            return 0;
        }
        int left=height(root.left);
        int right=height(root.right);
        if(Math.abs(left-right)>1){
            flag=false;
        }
        return 1+Math.max(left,right);
    }
}
```