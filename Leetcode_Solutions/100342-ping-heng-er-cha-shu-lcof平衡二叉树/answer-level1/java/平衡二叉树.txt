### 解题思路
判断一棵二叉树是否为平衡二叉树，其任意节点的左右子树的深度相差不能超过1.
本题可以在前一题（二叉树的高度）的基础上进行改进。
设置一个全局变量flag用于表示是否平衡，默认设置为true。
在height函数中边判断高度，边进行左右子树高度的比较。
如果高度差超过1，则把flag置为fasle。
最后返回flag。
由于只遍历了一遍二叉树，所以时间复杂度为O(n)

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
    boolean flag = true;
    public boolean isBalanced(TreeNode root) {
        if(root==null){
            return true;
        }
        height(root);
        return flag;
    }

    private int height(TreeNode root){
        if(root==null){
            return 0;
        }
        int left = height(root.left);
        int right = height(root.right);
        if(Math.abs(left-right)>1){
            flag = false;
        }
        return 1+Math.max(left, right);
    }
}
```