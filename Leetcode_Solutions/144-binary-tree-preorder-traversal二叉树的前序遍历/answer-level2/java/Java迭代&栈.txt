1. 输出当前节点值root.val(即存到list)
2. 若存在左子树，更新root为左子树，同时若存在右子树，右子树入栈
3. 若不存在左子树,弹出栈顶元素，root更新为栈顶元素（遍历右子树）
4. root为空时，遍历结束
```java
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
		List<Integer> list = new ArrayList<Integer>();
		if (root == null) {
			return list;
		}
		Stack<TreeNode> stack = new Stack<>();

		while (root != null) {
			//输出当前节点并遍历左子树
			while (root != null) {
				list.add(root.val);
				if (root.right != null) {
					//当右子树非空时入栈
					stack.push(root.right);
				}
				root = root.left;
			}
			//左子树遍历结束，遍历离左子树叶子节点最近的右子树(即栈顶元素)
			if (!stack.isEmpty()) {
				//更新根节点为右子树,开始遍历右子树
				root = stack.pop();
			}
		}
		return list;
    }
}
```
