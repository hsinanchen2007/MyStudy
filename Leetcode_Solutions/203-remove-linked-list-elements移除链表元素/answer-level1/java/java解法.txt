首先考虑head本身需要被删除的情况，然后设置虚拟头结点，依次向下迭代
```java
class Solution {
    
    public ListNode removeElements(ListNode head, int val) {
        while (head != null && head.val == val) {
            head = head.next;
        }
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        while (dummyHead.next != null) {
            if (dummyHead.next.val == val) {
                dummyHead.next = dummyHead.next.next;
            } else {
                dummyHead = dummyHead.next;
            }
        }
        return head;
    }
}
```
