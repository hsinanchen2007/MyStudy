### 解题思路
遍历二叉树，记录每个节点的深度和节点值。
当两个节点的节点深度一样但是父节点不同时返回真。

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
    TreeNode xParent;
    TreeNode yParent;
    int xHight=0;
    int yHight=0;
    public boolean isCousins(TreeNode root, int x, int y) {
        if(root==null) return false;
        helper(root,x,y,0,null);
        if(xHight==yHight&&xParent!=yParent){//父节点不同，深度相等
            return true;
        }else{
            return false;
        }

    }
 public void helper(TreeNode root,int x,int y,int d,TreeNode parent){
        if(root==null) return;
        d++;//节点的深度。
        if(root.val==x){
            xParent=parent;//x节点的父节点
            xHight=d;//x节点的深度
        }
        if(root.val==y){
            yParent=parent;//y节点的父节点
            yHight=d;//y节点的深度
        }
        helper(root.left,x,y,d,root);//递归遍历左子树
        helper(root.right,x,y,d,root);//递归遍历右子树
    }
}
```