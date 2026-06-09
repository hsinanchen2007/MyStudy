1. 先遍历到最后非零节点，不够的先用零节点补齐，不管l1还是l2，他们的长度都是相同的。
2. 再算一下最后一位，相加。
3. 最后检查进位是否非零，若非零直接next指向`0节点`
```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        int sum = 0;
        ListNode head = l1;
        while (l1.next != null || l2.next != null) {
            if (l1.next == null) {
                l1.next = new ListNode(0);
            }
            if (l2.next == null) {
                l2.next = new ListNode(0);
            }
            sum = l1.val + l2.val + carry;
            l1.val = sum % 10;
            carry = sum / 10;
            l1 = l1.next;
            l2 = l2.next;
        }
        sum = l1.val + l2.val + carry;
        l1.val = sum % 10;
        carry = sum / 10;
        if (carry > 0) {
            l1.next = new ListNode(1);
        }
        return head;
    }
}
```
