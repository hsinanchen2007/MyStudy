### 解题思路
此处撰写解题思路
思路的关键在于如何确定树的层数！
提供两个方法：
方法一：可以用HashMap记录每个节点的深度，这样需要遍历两遍树，显然不划算
方法二：在进行入队操作之前，记录下当前队列的size，这就是这层节点的个数，用一个size次数的循环，即可将该层的节点全部出队。重复这一步骤。
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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
		if (root == null) return new LinkedList<>();
		LinkedList<List<Integer>> ans = new LinkedList<>();
		Queue<TreeNode> q = new LinkedList<>();
		q.offer(root);
		while (! q.isEmpty()) {
			// 精妙之处
			int size = q.size();
			List<Integer> levelList = new ArrayList<>();
			for (int i=0; i<size; ++i) {
				TreeNode cur_tree = q.poll();
				if (cur_tree.left != null) q.offer(cur_tree.left);
				if (cur_tree.right != null) q.offer(cur_tree.right);
				levelList.add(cur_tree.val);
			}
			ans.offerFirst(levelList);
		}
		return ans;
    }
}
```