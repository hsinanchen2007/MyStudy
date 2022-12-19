### 解题思路
此处撰写解题思路

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
        ListNode curr = head;
        List<ListNode> list = new ArrayList<>();
        while (curr != null) {
            list.add(curr);
            curr = curr.next;
        }
        return buildTree(list, 0, list.size() - 1);
    }
    public TreeNode buildTree(List<ListNode> list, int start, int end) {
        if (start <= end) {
            int mid = (start + end) / 2;
            TreeNode root = new TreeNode(list.get(mid).val);
            root.left = buildTree(list, start, mid - 1);
            root.right = buildTree(list, mid + 1, end);
            return root;
        }
        return null;
    }
}
```