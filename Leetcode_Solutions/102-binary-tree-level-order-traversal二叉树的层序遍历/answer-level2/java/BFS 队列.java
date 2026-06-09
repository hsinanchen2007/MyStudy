### 解题思路
此处撰写解题思路

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result= new ArrayList<>();
		if (root == null) {
			return result;
		}
		Queue<TreeNode> nodeQueues = new LinkedList<>();
		nodeQueues.add(root);
		nodeQueues.add(null);
		 LinkedList<Integer> level_list = new LinkedList<Integer>();
		while (!nodeQueues.isEmpty()) {
			TreeNode node = nodeQueues.poll();
			if (node != null) {
				level_list.add(node.val);
                if (node.left != null) {
					nodeQueues.add(node.left);
				}
				if (node.right != null) {
					nodeQueues.add(node.right);
				}

			} else {
				result.add(level_list);
				level_list=new LinkedList<Integer>();
				if (nodeQueues.size() > 0) {
					nodeQueues.add(null);
				}
			}
		}
		return result;
    }
}
```