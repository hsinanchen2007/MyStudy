方法一：使用递归
```java []
class Solution {
	public int maxDepth(TreeNode root) {
		if (root == null) return 0;
		int maxDepth = Math.max(maxDepth(root.left), maxDepth(root.right));
		return maxDepth + 1;
	}
}
```
方法二：使用迭代(层序遍历访问节点)
```java []
class Solution {
	public int maxDepth(TreeNode root) {
		Queue<TreeNode> queue = new LinkedList<>();
		if (root==null) return 0;
		
		queue.offer(root);
		int levelSize = 1;
		int height = 0;
		while(queue.isEmpty()==false) {
			
			TreeNode node = queue.poll();
			levelSize --;
			if (node.left != null) queue.offer(node.left);
			if (node.right != null) queue.offer(node.right);
			
			if (levelSize==0) {
				height++;
				levelSize = queue.size();
			}
		}
		return height;
    }
}
```