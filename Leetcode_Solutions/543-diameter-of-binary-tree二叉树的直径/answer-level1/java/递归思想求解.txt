### 解题思路
此处撰写解题思路
思想：最长结点数一定是某个子结点的左右两支。于是用递归的思想，求出每个结点以自身为root时，左右两棵子树的深度，然后保留最大值。
看递归部分代码：不断计算子左右两个子结点的深度，直至访问到叶结点。返回两个子结点深度较大者，别忘了+1，因为需要加上此时的root结点本身一个深度啊！
最后为什么要减1呢，因为根结点算了两次！！
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
	int ans = 1;

	public int diameterOfBinaryTree(TreeNode root) {
		if (root == null) return 0;		
		depth(root);
		return ans - 1;
	}
	
	public int depth(TreeNode root) {
		if (root == null) return 0;
		int L = depth(root.left);
		int R = depth(root.right);
		ans = Math.max(ans, L+R+1);
		return Math.max(L, R) + 1;
    }
}
```