### 解题思路
此处撰写解题思路

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
    public int largestBSTSubtree(TreeNode root) {
        if(root==null)
            return 0;
        if(isBST(root))
            return getCount(root);
        int L=largestBSTSubtree(root.left);
        int R=largestBSTSubtree(root.right);
        return Math.max(L,R);
    }

    private boolean isBST(TreeNode root){
        return isBST(root,Integer.MIN_VALUE,Integer.MAX_VALUE);
    }
    //下面写如何判断该树是否是二叉搜索树的函数
    private boolean isBST(TreeNode root,int min,int max){
        if(root==null)
            return true;
        return min<root.val&&root.val<max&&isBST(root.left,min,root.val)&&isBST(root.right,root.val,max);    
    }

    private int getCount(TreeNode root){
        if(root==null)
            return 0;
        return 1+getCount(root.left)+getCount(root.right);
    }
}
```