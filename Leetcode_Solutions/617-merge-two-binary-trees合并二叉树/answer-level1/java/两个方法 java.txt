```java
// 617. 合并二叉树
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
//生成新树
class Solution {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if(t1==null&&t2==null){
        	return null;
        }
        TreeNode t3 = new TreeNode((t1==null?0:t1.val)+(t2==null?0:t2.val));
        t3.left = mergeTrees(t1==null?null:t1.left,t2==null?null:t2.left);
        t3.right = mergeTrees(t1==null?null:t1.right,t2==null?null:t2.right);
        return t3;
    }
}
//把2并到1上
class Solution {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if((t1==null&&t2==null)||t1==null){
        	return t;
        }
        
        if(t2==null){
        	return t1;
        }
        t1.val +=t2.val;
        t1.left = mergeTrees(t1.left,t2.left);
        t1.right = mergeTrees(t1,right,t2.right);
        return t1;
    }
}
```java