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
    public void reorderList(ListNode head) {
        if(head==null)
        return ;
        ListNode mid=findmid(head);//找到链表的中间点
        ListNode l1=head;
        ListNode l2=reverse(mid.next);
        mid.next=null;//反转后部分链表
        while(l2!=null&&l1!=null)
        {
            ListNode next=l1.next;
            l1.next=l2;
            l2=l2.next;
            l1.next.next=next;
            l1=next;
        }
    }
    public ListNode findmid(ListNode head){//快慢指针找中间点
        ListNode fast=head;
        ListNode slow =head;
        while(fast != null&&fast.next!=null)
        {
            fast=fast.next.next;
            slow=slow.next;
        }
        return slow;
    }
    public ListNode reverse(ListNode head){
        ListNode newhead=null;
        while(head!=null)
        {
            ListNode next=head.next;
            head.next = newhead;
            newhead = head;
            head=next;
        }
        return newhead;
    }
}
```