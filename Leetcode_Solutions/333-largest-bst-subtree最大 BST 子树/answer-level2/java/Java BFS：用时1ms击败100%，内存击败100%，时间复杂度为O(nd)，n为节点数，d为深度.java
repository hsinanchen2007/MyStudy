1. **从根节点进行BFS，若判定为BST，则停止向下遍历，保存节点数**
2. **节点数大于当前节点数更新当前节点数**
3. **最后返回该节点数**

```
private double val = -Double.MAX_VALUE;

private int count = 0;

private boolean isBST(TreeNode node)
{
	if (node == null)
	{
		return true;
	}
	if (isBST(node.left) && val < node.val)
	{
		count++;
		val = node.val;
		return isBST(node.right);
	}
	return false;
}
public int largestBSTSubtree(TreeNode root)
{
	Queue<TreeNode> queue = new LinkedList<>();
	if (root != null)
	{
		queue.add(root);
	}
	int result = 0;
	while (!queue.isEmpty())
	{
		TreeNode node = queue.poll();
		if (!isBST(node))
		{
			if (node.left != null)
			{
				queue.add(node.left);
			}
			if (node.right != null)
			{
				queue.add(node.right);
			}
		}
		else 
		{
			result = count > result ? count : result;
		}
		count = 0;
		val = -Double.MAX_VALUE;
	}
	return result;
}
```
提交结果：
![运行结果.png](https://pic.leetcode-cn.com/a936460af33504c4ed9e489ee292c7edc5a507f0e891232210215a0f5ddb64ec-%E8%BF%90%E8%A1%8C%E7%BB%93%E6%9E%9C.png)