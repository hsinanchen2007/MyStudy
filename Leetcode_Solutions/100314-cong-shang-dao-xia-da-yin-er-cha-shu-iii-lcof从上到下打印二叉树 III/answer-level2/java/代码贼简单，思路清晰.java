### 解题思路
思路贼清晰， 双端队列实现之字形

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
    List<List<Integer>> rs = new ArrayList<>();
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) { return rs; }
		Queue<TreeNode> q = new ArrayDeque<>();
		q.offer(root);
		int level = 0;
		while (!q.isEmpty()) {
			rs.add(new LinkedList<>());
			int sz = q.size();
			for (int i = 0; i < sz; ++i) {
				TreeNode cur = q.poll();
                // 这里使用双端队列实现之字形
				LinkedList clist = (LinkedList) rs.get(level);
				boolean obj = (level & 1) == 1 ? clist.offerFirst(cur.val) : clist.offerLast(cur.val);
				if (cur.left != null) { q.offer(cur.left); }
				if (cur.right != null) { q.offer(cur.right); }
			}
			++ level;
		}
		return rs;
    }
}
```