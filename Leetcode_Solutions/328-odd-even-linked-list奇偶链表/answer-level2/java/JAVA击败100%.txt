首先将原节点的子节点分离出来作为第二个头结点
1. 将奇链表的下一个节点指定
2. 将偶链表的下一个节点指定
重复1,2操作直到出现空的3种情况
最后将偶链表拼到奇链表的后面
```
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null) return null;
        ListNode head2 = head.next;
        ListNode temp1 = head;
        ListNode temp2 = head2;
        while (temp2 != null && temp1.next != null && temp2.next != null) {
            temp1.next = temp1.next.next;
            temp2.next = temp2.next.next;
            temp1 = temp1.next;
            temp2 = temp2.next;
        }
        temp1.next = head2;
        return head;
    }
}
```
