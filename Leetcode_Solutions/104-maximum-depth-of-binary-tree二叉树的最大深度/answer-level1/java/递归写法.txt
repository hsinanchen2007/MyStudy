### 解题思路
递归写法

执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :38.8 MB, 在所有 Java 提交中击败了30.56%的用户

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
    public int max(int a,int b) {
		if(a>b)
			return a;
		else
			return b;
	}
	public int maxDepth(TreeNode root) {
		// 若没有根节点，返回0
		if(root==null)
			return 0;
		//若左右孩子都为空，返回1
		if(root.left==null && root.right==null)
			return 1;
		// 若左孩子有，右孩子为空
		else if(root.left==null) {
			return 1+maxDepth(root.right);
		}
		// 若右孩子有，左孩子为空
		else if(root.right==null) {
			return 1+maxDepth(root.left);
		}
		// 若左右孩子都有
		else {
			return 1+ max(maxDepth(root.left),maxDepth(root.right));
		}
    }
}
```