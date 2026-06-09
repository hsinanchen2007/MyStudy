```
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
        if(head == null)
            return null;
        if(head.next == null) {
            return new TreeNode(head.val);
        }
        ListNode w = head;
        ListNode r = head.next;
        ListNode p = head;
        while(r != null) {
            p = w;
            w = w.next;
            r = r.next;
            if(r != null)
                r = r.next;
        }
        TreeNode rt = new TreeNode(w.val);
        p.next = null;
        ListNode right = w.next;
        rt.left = sortedListToBST(head);
        rt.right = sortedListToBST(w.next);
        return rt;
    }
}
```
