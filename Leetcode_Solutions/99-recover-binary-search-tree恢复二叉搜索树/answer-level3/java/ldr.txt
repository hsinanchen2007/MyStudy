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
   public void recoverTree(TreeNode root) {

		ldr(root);

		if (wrong != null) {
			int temp=wrong.val;
			wrong.val=special.val;
			special.val = temp;
		
		}
	}


	TreeNode wrong = null;
    TreeNode special=null;//错误的两个节点是前后节点的情况
	TreeNode last = new TreeNode(Integer.MIN_VALUE);

	void ldr(TreeNode root) {
		if (root == null) {
			return;
		}
		ldr(root.left);
		if (root.val < last.val) {
			if (wrong == null) {
				wrong = last;
                special=root;
			}else{
				int temp=wrong.val;
				wrong.val=root.val;
				root.val = temp;
				wrong=null;
			}

		}
		last = root;
		ldr(root.right);
	}
}
```