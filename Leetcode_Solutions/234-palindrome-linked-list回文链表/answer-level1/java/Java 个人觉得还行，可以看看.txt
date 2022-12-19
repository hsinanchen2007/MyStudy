就是最后一个值和第一个值对比
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
		RE(head, head);
		return flag;
	}
	boolean flag = true;
	public ListNode RE(ListNode h, ListNode t){
		if(h == null)
			return t;
		ListNode node = RE(h.next, t);
		if(node.val != h.val)
			flag = false;
		return node.next;
	}
}