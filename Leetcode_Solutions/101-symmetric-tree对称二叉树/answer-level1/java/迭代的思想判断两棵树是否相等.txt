### 解题思路
这题与第100题有类似之处。
唯一值得一提的是，对于处理左右子树时，入栈的处理有所不同。
对于左子树，大概是前序搜索，右子树是后序搜索吧。总之入栈的顺序是，左边的先入右子树，后入栈左子树，这样pop出来的就先是左子树了，而右边则恰好相反，这样就可以对称的比较了。

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
    public boolean isSymmetric(TreeNode root) {
		// 如果为空树，或只有根节点，是对称的
		if (root == null || root.left == null && root.right == null) return true;
		Stack<TreeNode> s1 = new Stack<>();
		Stack<TreeNode> s2 = new Stack<>();
		TreeNode l = root.left;
		TreeNode r = root.right;
		s1.push(l);
		s2.push(r);
		while(! s1.isEmpty()) {
			TreeNode cur1 = s1.pop();
			TreeNode cur2 = s2.pop();
			// 一棵树是空，而另一棵树不空，肯定不对称
			if (cur1==null&&cur2!=null || cur2==null&&cur1!=null) return false;
			// 都为空，此时是对称的，继续判断后面的情况
			else if (cur1 == null && cur2 == null) continue;
			// 节点值不相等，肯定也不对称
			else if (cur1.val != cur2.val) return false;
			// 左边先压入右子树，保证先pop出左子树；右边先压入左子树，保证先pop出右子树
			s1.push(cur1.right); s1.push(cur1.left);
			s2.push(cur2.left); s2.push(cur2.right);
		}
		return true;
    }
}
```