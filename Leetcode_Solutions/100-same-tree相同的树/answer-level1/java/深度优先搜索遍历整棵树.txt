### 解题思路
1. 新建两个栈，深度搜索，栈中存储的是节点
2. 遍历其中一棵树，比较其节点值
3. 将其右、左子树压中栈中（当子树是空节点时，也会压中栈中）
4. 由于null节点没有val，所以先判断push出来的是不是null节点，如果一个是，一个不是，那肯定不相同，如果两个都是，那么不比较他们的节点值，也不压他们的子节点入栈，因为没有，如果都不是null节点，再比较他们的值。
5. 最后一点，我觉得是最巧妙的地方，当一棵树为空后，判断另一棵树是否为空，如果不是，也是false。
6. 可惜时间上并不快，复杂度应该是O（N），N为树p的节点个数，空间复杂度为O（N+M），N,M分别是两棵树的节点个数。学习一下更高效的解法！

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
    public boolean isSameTree(TreeNode p, TreeNode q) {
		if (p==null && q==null) return true;
		Stack<TreeNode> s1 = new Stack<>();
		Stack<TreeNode> s2 = new Stack<>();
		s1.push(p); s2.push(q);
		while (! s1.isEmpty()) {
			TreeNode cur1 = s1.pop();
			TreeNode cur2 = s2.pop();
            if (cur1==null&&cur2!=null || cur2==null&&cur1!=null) return false;
            else if (cur1==null && cur2==null) continue;
            else if (cur1.val != cur2.val) return false;
			s1.push(cur1.right); s1.push(cur1.left);
			s2.push(cur2.right); s2.push(cur2.left);
		}
		return s2.isEmpty();
    }
}
```