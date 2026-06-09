### 解题思路
构建一个新链表，两个指针分别从l1和l2开头扫描，选取较小的一个尾插法插入新链表。最后把还有剩余的链表插入到新链表最后。

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
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head1=l1;
        ListNode head2=l2;
        ListNode head0=new ListNode(0),head=head0;
        while(head1!=null&&head2!=null)
        {
            if(head1.val<=head2.val)
            {
                head.next=head1;
                head=head.next;
                head1=head1.next;
            }
            else
            {
                head.next=head2;
                head=head.next;
                head2=head2.next;
            }
        }
        if(head1!=null)
            head.next=head1;
        if(head2!=null)
            head.next=head2;
        return head0.next;
    }
}
```