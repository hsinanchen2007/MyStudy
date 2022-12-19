### 解题思路
RT，O(n)。
已知，如果要完成p.pre=p.next，因为不是双向链表，所以要加一个指针，指向前一个节点。而且pre初始为null。

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
    public ListNode reverseList(ListNode head) {
        if(head==null)return head;//空链表
        if(head.next==null)return head;//单节点
        ListNode pre=null;
        ListNode p=head;
        ListNode item=null;
        while(p!=null){
            item=p.next;
            p.next=pre;
            pre=p;
            p=item;
        }
        return pre;
    }
}
```