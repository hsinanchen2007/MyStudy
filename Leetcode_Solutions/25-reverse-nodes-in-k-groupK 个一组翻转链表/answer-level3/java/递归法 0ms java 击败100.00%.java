### 解题思路
因为要进行翻转，所以我们先写一个翻转的函数。然后遍历k个节点，分别标记了首尾（这里分别是head和current）。如果节点不足k则直接返回head。如果节点数不小于k，先用temp记录current.next便于对剩余链表进行递归。将current.next指向null使链表分为两半。对前一半进行翻转，翻转后原先的head成为了尾节点，head.next指向递归返回的结果使链表重新连接起来。

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
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head==null||head.next==null)return head;
        ListNode res;
        ListNode current=new ListNode(-1);
        current.next=head;
        int i=0;
        while(i<k&&current.next!=null){
            i++;
            current=current.next;
        }
        if(i<k){
            return head;
        }else{
            ListNode temp=current.next;
            current.next=null;
            res=reverse(head);
            head.next=reverseKGroup(temp,k);
        }
        return res;
    }
    public ListNode reverse(ListNode head){
        if(head==null||head.next==null)return head;
        ListNode pre=head,current=head.next;
        pre.next=null;
        while(current!=null){
            ListNode temp=current.next;
            current.next=pre;
            pre=current;
            current=temp;
        }
        return pre;
    }
}
```