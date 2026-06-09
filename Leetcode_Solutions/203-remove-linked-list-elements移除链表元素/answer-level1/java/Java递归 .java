# 思路
递归，看代码就明白了，没啥说的。
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
    public ListNode removeElements(ListNode head, int val) {
        if(head == null)
            return head;
        if(head.val == val)
            return removeElements(head.next, val);
        else{
            head.next = removeElements(head.next, val);
            return head;
        }
    }
}
```
