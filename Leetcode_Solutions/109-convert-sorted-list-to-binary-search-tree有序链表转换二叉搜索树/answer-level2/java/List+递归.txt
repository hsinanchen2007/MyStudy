### 解题思路


### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
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
    	public TreeNode sortedListToBST(ListNode head) {

		ArrayList<Integer> list = new ArrayList<>();
		while (head != null) {
			list.add(head.val);
			head = head.next;
		}
		return create(list, 0, list.size() - 1);

	}

	TreeNode create(ArrayList<Integer> list, int start, int end) {
		if (start == end) {
			return new TreeNode(list.get(end));
		}
		if (start > end) {
			return null;
		}
		int mid = (start + end) / 2;
		TreeNode node = new TreeNode(list.get(mid));
		node.left = create(list, start, mid - 1);
		node.right = create(list, mid + 1, end);
		return node;
	}
}
```