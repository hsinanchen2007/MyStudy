### 解题思路
这道题和rotting oranges那题非常相似，那道题是求腐烂的时间，这道题是求树的深度，我感觉是一样的。我的代码应该十分好理解，可惜用时和空间都不够好，学习学习优秀的做法去。

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
    public int maxDepth(TreeNode root) {
		if (root == null) return 0;
		int max = 0;
		HashMap<TreeNode, Integer> map = new HashMap<>();
		Stack<TreeNode> s = new Stack<>();
		TreeNode cur = root;
		s.push(cur);
		map.put(cur, 1);
		while (! s.isEmpty()) {
			cur = s.pop();
			int depth = map.get(cur);
			max = Math.max(max, depth);
			if (cur.right != null) {
				s.push(cur.right);
				map.put(cur.right, depth+1);
			}
			if (cur.left != null) {
				s.push(cur.left);
				map.put(cur.left, depth+1);
			}
		}
		return max;

    }
}
```