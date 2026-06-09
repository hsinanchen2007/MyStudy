### 解题思路
此处撰写解题思路
![镜像二叉树.gif](https://pic.leetcode-cn.com/95613c19f272fd44c8666f995786157b6cdeb414d1f2d535d007dd8579b61153-%E9%95%9C%E5%83%8F%E4%BA%8C%E5%8F%89%E6%A0%91.gif)

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
    public TreeNode invertTree(TreeNode root) {
		makeInvertTree(root);
		return root;
	}
	public static void makeInvertTree(TreeNode root) {
		if(root==null) {return ;}
		TreeNode temp;
		if(root.left!=null && root.right!=null) {
			temp=root.left;
			root.left=root.right;
			root.right=temp;
			makeInvertTree(root.left);
			makeInvertTree(root.right);
		}else if(root.left!=null && root.right==null) {
			temp=root.left;
			root.left=null;
			root.right=temp;
			makeInvertTree(root.right);
		}else if(root.left==null && root.right!=null) {
			temp=root.right;
			root.right=null;
			root.left=temp;
			makeInvertTree(root.left);
		}
	}
}
```