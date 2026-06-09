### 解题思路  1.先定义一个整型的最大值，以后依次通过中序遍历来搜索二叉树，同时记录每相邻两个
结点值的差值，利用Math.min来得到最小值。
              2.二叉搜索树的特点是，通过中序遍历可以得到一个升序的排列。


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
    TreeNode preNode=null;
    int minDiff=Integer.MAX_VALUE;
    public int getMinimumDifference(TreeNode root) {
        getMin(root);
        return minDiff;
    }
    public void getMin(TreeNode root){ 
        if(root==null) return;
        getMin(root.left);
        if(preNode!=null) minDiff=Math.min(minDiff,root.val-preNode.val);
        preNode=root;
        getMin(root.right);
    }
    
}
```