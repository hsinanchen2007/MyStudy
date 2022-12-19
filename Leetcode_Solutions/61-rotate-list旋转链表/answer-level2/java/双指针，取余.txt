### 解题思路
做标记指针，
由于K指针可能会超过链表长度，所以需要先遍历整个链表，记录链表长度。
先用快慢指针找到倒数第K个节点，之后记录倒数第k个节点的前节点，让他的next指向空，
并且让快指针（走到头了），直接让他指向头结点，
while循环条件就是（first.next!=null）
循环结束时，表示到达尾部，直接令first指向head，并且此时的second的next是新的头结点
所以将new_head=second.next;
second.next=null;尾部重置。
代码是粗糙的代码，用了两个last来进行记录，完全可以通过更改循环终止条件，避免这两个last。（梳理思路的时候发现了这个循环条件可以更改，所以写题解是真的有用，精炼跟总结思路！！！冲冲冲）


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
    public ListNode rotateRight(ListNode head, int k) {
        ListNode first=head;
        if(head==null||k==0)
            return head;
        ListNode head_copy=head;
        int count=0;
        ListNode count_node=head;
        while(count_node!=null)
        {
            count_node=count_node.next;
            count++;
        }
        k=k%count;
        if(k==0)
            return head;
        for (int i=0;i<k;i++)
            head=head.next;
        ListNode first_last=head;
        ListNode second_last=head;
        while(head!=null)
        {
            second_last=head;
            head=head.next;

            first_last=first;
            first=first.next;
        }
        first_last.next=null;
        second_last.next=head_copy;
        return first;
    }
}
```