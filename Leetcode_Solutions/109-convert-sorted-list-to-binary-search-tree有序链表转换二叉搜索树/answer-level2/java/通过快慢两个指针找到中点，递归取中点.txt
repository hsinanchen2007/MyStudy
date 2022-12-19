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
       return get(head);
    }
    private TreeNode get(ListNode ln){
         if(ln==null)return null;
        ListNode fast = ln;
        ListNode slow = ln;
        ListNode pre = new ListNode(0);
        pre.next = ln;
        while(fast.next!=null&&fast.next.next!=null){
            slow = slow.next;
            fast = fast.next.next;
            pre = pre.next;
        }
        TreeNode par = new TreeNode(slow.val);
        par.right = get(slow.next);
        pre.next = null;
        if(ln!=slow)par.left = get(ln);
        return par;
    }
}
```
