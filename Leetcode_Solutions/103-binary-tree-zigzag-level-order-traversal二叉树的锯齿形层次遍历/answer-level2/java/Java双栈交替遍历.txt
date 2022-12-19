在所有Java 提交中击败了99.13%的用户。思路很好理解。
解题思路：
1. 把所有层分为奇偶层，将根节点看作第0层(偶数层)，并入栈`evenLevel`
2. 遍历偶数层的节点时，将**偶数层**的节点栈`evenLevel`依次出栈，**同时**把出栈节点的子树按`left`、`right`分别**入奇数层**节点栈`oddLevel`，直到偶数层的栈为空
3. 遍历奇数层的节点时，将**奇数层**的节点栈`oddLevel`依次出栈，**同时**把出栈节点的子树按`right`、`left`分别**入偶数层**节点栈`evenLevel`，直到奇数层的栈为空
4. 第2、3步骤交替进行，当两个栈都为空时结束锯齿遍历
```java
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
		List<List<Integer>> res = new ArrayList<>();
		Stack<TreeNode> evenLevel = new Stack<>();//记录偶数层的节点栈
		Stack<TreeNode> oddLevel = new Stack<>();//记录奇数层的节点栈
		evenLevel.push(root);
		for (int i = 0; !evenLevel.isEmpty() || !oddLevel.isEmpty(); i++) {
			List<Integer> cur = new ArrayList<Integer>();
			if ((i & 1) == 0) {
				// 偶数层,从0开始
				while (!evenLevel.isEmpty()) {
					TreeNode pop = evenLevel.pop();
					if (pop != null) {
						cur.add(pop.val);
						// 左子树先入栈，因为下一层（奇数层）访问顺序是:右节点->左节点
						// 根据栈的FILO,左节点先入栈
						oddLevel.push(pop.left);
						oddLevel.push(pop.right);
					}
				}
			} else {
				// 奇数层
				while (!oddLevel.isEmpty()) {
					TreeNode pop = oddLevel.pop();
					if (pop != null) {
						cur.add(pop.val);
						// 右子树先入栈，因为下一层（偶数层）访问顺序是:左节点->右节点
						evenLevel.push(pop.right);
						evenLevel.push(pop.left);
					}
				}
			}
			if (!cur.isEmpty()) {
				res.add(cur);
			}
		}
		return res;
    }
}
```
