栈模拟递归过程（函数递归调用本质也是栈）：
1. 将根节点root入栈
2. 栈为空时说明树遍历结束，退出循环
3. 当root非空时，将其左子树入栈,stack.push(root.left),并将root更新为左子树,直到左子树为null,执行步骤4
4. 此时左子树为null，弹出栈顶元素，若栈顶元素非null，输出其值，且将其右子树入栈，root更新为右子树，回到步骤3

```java
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
		List<Integer> list = new ArrayList<Integer>();
		if (root == null) {
			return list;
		}

		Stack<TreeNode> stack = new Stack<>();
		//1.将根节点root入栈
		stack.push(root);
		//2. 栈为空时说明树遍历结束，退出循环
		while (!stack.isEmpty()) {
		//3.当root非空时，将其左子树入栈,stack.push(root.left),
		//  并将root更新为左子树,直到左子树为null,执行步骤4
			if (root != null && root.left != null) {
				//提前对左子树判空，优化内存消耗，减少stack.push(null)
				stack.push(root.left);
				root = root.left;
			} else {
				//4. 此时左子树为null，弹出栈顶元素
				TreeNode pop = stack.pop();
				//若栈顶元素非null，输出其值，且将其右子树入栈，
				//root更新为右子树，回到步骤3
				if (pop != null) {
					list.add(pop.val);
					//提前对右子树判空，优化内存消耗
					if (pop.right != null) {
						stack.push(pop.right);
						root = pop.right;
					}
				}
			}
		}
		return list;
    }
}
```
