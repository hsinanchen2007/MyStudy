[https://blog.csdn.net/jjy19971023/article/details/104539743]()### 解题思路
判断所有情况就好
具体思路详见https://blog.csdn.net/jjy19971023/article/details/104539743

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
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
         TreeNode re=null;
		 if(root.val<p.val){//在右子树
			 root=root.right;
			 if(root!=null){
				re= inorderSuccessor(root, p); 
			 }else
				 return null;
		 }
		else if(root.val==p.val){
			 if(root.right!=null){
				 re=findleft(root.right);
			 }
			 return re;
		 }
		else if(root.val>p.val){
			 if(root.left!=null&&root.left.right==null&&root.left.val==p.val){
				 return root;
			 }
			 else  if(root.left!=null&&root.left.right!=null&&root.left.val==p.val){
				 return findleft(root.left.right);
			 }
			 else if(root.left!=null&&root.left.val<p.val){
				 re =inorderSuccessor(root.left, p)==null? root:inorderSuccessor(root.left, p);
				 
			 }
			 else if(root.left!=null&&root.left.val>p.val){
			 re=inorderSuccessor(root.left, p);
			 }else
				 return null;
		 }
		 return re;
		
    }
    	 private TreeNode findleft(TreeNode root) {
		while(root.left!=null){
			root=root.left;
		}
		return root;
         }
}
```