### 解题思路
见代码注释

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
		LinkedList<TreeNode> linkedList = new LinkedList<>();
		List<List<Integer>> lists = new LinkedList<>();
		if (root == null)
			return lists;
		int flag = -1, cnt = 0;//flag用来判定是奇数层还是偶数层，cnt用来保证每一层的遍历
		linkedList.add(root);
		while (!linkedList.isEmpty()) {
			//每一层遍历cnt重新赋值为链表长度，即此层节点个数，flag表示第几层
			cnt = linkedList.size();
			++flag;
			List<Integer> list = new LinkedList<>();
			if (flag % 2 != 0) {//奇数层
				while (cnt-- > 0) {
				//从链表尾部开始遍历
					TreeNode tem = linkedList.removeLast();
					list.add(tem.val);
				//从链表首部按照先右后左的顺序添加节点，这样下一层从链表首部开始遍历的结果才会正确
					if (tem.right != null)
						linkedList.addFirst(tem.right);
					if (tem.left != null)
						linkedList.addFirst(tem.left);
				}
			} else {//偶数层正常从链表首部开始遍历、链表尾部按照先左后右的顺序添加节点即可
				while (cnt-- > 0) {
					TreeNode tem = linkedList.removeFirst();
					list.add(tem.val);
					if (tem.left != null)
						linkedList.add(tem.left);
					if (tem.right != null)
						linkedList.add(tem.right);
				}
			}
			lists.add(list);
		}
		return lists;
	}
}
```