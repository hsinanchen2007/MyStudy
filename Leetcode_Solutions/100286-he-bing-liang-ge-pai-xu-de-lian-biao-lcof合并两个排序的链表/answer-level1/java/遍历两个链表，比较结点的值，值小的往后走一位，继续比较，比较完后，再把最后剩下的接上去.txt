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
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head1=l1;
        ListNode head2=l2;
        ListNode last=new ListNode(1);
        ListNode head=last;
        while(head1!=null&&head2!=null){
            if(head1.val<head2.val){
                ListNode node1=new ListNode(head1.val);
                node1.next=null;
                last.next=node1;
                last=node1;
                head1=head1.next;
            }
            else if(head1.val==head2.val){
                ListNode node1=new ListNode(head1.val);
                ListNode node2=new ListNode(head2.val);
                node2.next=null;
                node1.next=node2;
                last.next=node1;
                last=node2;
                head1=head1.next;
                head2=head2.next;
            }
            else{
                ListNode node2=new ListNode(head2.val);
                node2.next=null;
                last.next=node2;
                last=node2;
                head2=head2.next;
            }
        }
        if(head1!=null){
            last.next=head1;
        }
        if(head2!=null){
            last.next=head2;
        }
        return head.next;
    }
}
```