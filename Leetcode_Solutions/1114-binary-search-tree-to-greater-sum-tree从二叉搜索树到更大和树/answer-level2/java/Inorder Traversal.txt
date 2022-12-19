### 解题思路
Step 1:Just inorder traverse the BST and save the results in an array.
Step 2:The array is accumulated from backward,
Step 3:Final array's values given to BST with inorder traversal.

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

	int [] inorder = new int[100];
	int index=0;
	public void obtainValues(TreeNode root){
		if (root.left!=null){
			obtainValues(root.left);
		}
		//push an element
		this.inorder[index]=root.val; index = index+1;
		if (root.right!=null){
			obtainValues(root.right);
		}
	}
	public void giveValues(TreeNode root){
		if (root.left!=null){
			giveValues(root.left);
		}
		//push an element
		root.val = this.inorder[index]; index = index+1;
		if (root.right!=null){
			giveValues(root.right);
		}
	}
    public TreeNode bstToGst(TreeNode root) {
		if (root==null){
			return root;
		}
		index = 0;
		obtainValues(root);
		int sum = 0;
		index = index-1;
		while(index>=0){
			sum = sum+inorder[index];
			inorder[index]=sum;
			index = index-1;
		}
		index = 0;
		giveValues(root);
		return root;
        
    }
}
```