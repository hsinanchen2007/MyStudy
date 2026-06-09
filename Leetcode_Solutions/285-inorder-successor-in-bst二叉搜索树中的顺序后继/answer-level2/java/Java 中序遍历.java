**提交结果：**
![运行结果.png](https://pic.leetcode-cn.com/e9df55bdfce241dc306595f6d87dcdfa99c714122d8b74f003199bbd00bbe526-%E8%BF%90%E8%A1%8C%E7%BB%93%E6%9E%9C.png)
**代码：**
```
public class Solution
{
	boolean isFound = false;
	
	TreeNode tree;
	
	private TreeNode inOrder(TreeNode node, int val)
	{
		if (node.left != null && (tree = inOrder(node.left, val)) != null)
		{
			return tree;
		}
		if (isFound)
		{
			return node;
		}
		if (node.val == val)
		{
			isFound = true;
		}
		if (node.right != null && (tree = inOrder(node.right, val)) != null)
		{
			return tree;
		}
		return null;
	}
	
	public TreeNode inorderSuccessor(TreeNode root, TreeNode p)
	{
		if (root == null)
		{
			return null;
		}
		return inOrder(root, p.val);
	}
}
```