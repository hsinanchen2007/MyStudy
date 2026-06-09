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
    public ListNode partition(ListNode head, int x) {//借助两个头结点，分别存储大的小的，然后连接
        ListNode head1 = new ListNode(0);
        ListNode head2 = new ListNode(0);
        ListNode p = head;
        ListNode h1 = head1;
        ListNode h2 = head2;
        while(p != null) {
            if(p.val < x) {
                h1.next = p;
                h1 = h1.next;
            }
            else {
                h2.next = p;
                h2 = h2.next;
            }
            p = p.next;
        }
        h2.next = null;
        h1.next = head2.next;
        return head1.next;
    }
}
```

python3
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        head1 = ListNode(0)
        head2 = ListNode(0)
        p = head
        h1 = head1
        h2 = head2
        while p:
            if p.val < x:
                h1.next = p
                h1 = h1.next
            else:
                h2.next = p
                h2 = h2.next
            p = p.next
        h2.next = None
        h1.next = head2.next
        return head1.next
```
