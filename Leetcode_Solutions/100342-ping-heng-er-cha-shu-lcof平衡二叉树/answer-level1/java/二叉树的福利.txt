### 解题思路
二叉树最重要的遍历，面试常问。这篇文章写的真的棒，二叉树的进阶遍历morris
https://zhuanlan.zhihu.com/p/101321696

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
    boolean res=true;
    public boolean isBalanced(TreeNode root) {
        maxDepth(root);
        return res;
    }
    public int maxDepth(TreeNode root){
        if(root==null){
            return 0;
        }
        int left=maxDepth(root.left);
        int right=maxDepth(root.right);
        if(left-right>1){
            res=false;
        }
        if(right-left>1){
            res=false;
        }
        return left>right?left+1:right+1;
    }
}
```