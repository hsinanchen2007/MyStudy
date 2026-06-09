### 解题思路
1.先前序遍历每个节点；
2.若有子节点，则交换子节点；
3.当交换完所有非叶子节点的左右子节点之后，就得到了镜像

![镜像二叉树.gif](https://pic.leetcode-cn.com/5b524521b5e815367b63995e7a02c2ff1f554d51a793caa7e29fb64123704900-%E9%95%9C%E5%83%8F%E4%BA%8C%E5%8F%89%E6%A0%91.gif)

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
    public static TreeNode mirrorTree(TreeNode root) {
		makeMirrorTree(root);
		return root;
	}
	public static void makeMirrorTree(TreeNode root) {
		if(root==null) {
			return ;
		}
		TreeNode temp;
		if(root.left !=null && root.right!=null) {
			temp=root.left;
			root.left=root.right;
			root.right=temp;
			makeMirrorTree(root.left);
			makeMirrorTree(root.right);
		}else if(root.left!=null &&root.right==null) {
			temp=root.left;
			root.left=null;
			root.right=temp;
			makeMirrorTree(root.right);
		}else if(root.left==null && root.right!=null) {
			temp=root.right;
			root.right=null;
			root.left=temp;
			makeMirrorTree(root.left);
		}
	}
}
```