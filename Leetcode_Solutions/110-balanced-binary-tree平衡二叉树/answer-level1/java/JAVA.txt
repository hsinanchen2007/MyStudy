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
    public boolean isBalanced(TreeNode root) {
    if (root==null){
        //空树认为是平衡的
        return true;
    }
    if (root.left==null&&root.right==null){
        //没有节点也认为是平衡的
        return true;
    }
    //第一步：自己的左右子树高度差是否<=1;
    int leftDepth=maxDepth(root.right);
    int rightDepth=maxDepth(root.left);
    if(leftDepth-rightDepth>1||leftDepth-rightDepth<-1){//记得是比较绝对值
        return false;
    }
    //第二步：&&左右子树是否分别为平衡二叉树（递归判断）
    return isBalanced(root.right)&&isBalanced(root.left);
    }
    public int maxDepth(TreeNode root) {
       if (root==null){
           return  0;
       }
       if (root.right==null&&root.left==null){
           return 1;
       }
       int result=Math.max(maxDepth(root.left),maxDepth(root.right))+1;
       return result;
    }
}
```