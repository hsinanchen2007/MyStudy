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
    public ListNode plusOne(ListNode head) {
        //方法：翻转原有单链表，模拟加一的过程后再翻转回去
        head=reverse(head);
        ListNode pre=null, cur=head;
        int t=1;
        while(t!=0&&cur!=null){
            t+=cur.val;
            cur.val=t%10;
            t/=10;
            pre=cur;
            cur=cur.next;
        }
        //如果说没有后面的节点了(t=1)
        if(t==1)
            pre.next=new ListNode(1);
        return reverse(head);
    }

    public ListNode reverse(ListNode head)
    {
        ListNode pre=null,cur=head,next=null;
        while(cur!=null){
            next=cur.next;
            cur.next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
}
```