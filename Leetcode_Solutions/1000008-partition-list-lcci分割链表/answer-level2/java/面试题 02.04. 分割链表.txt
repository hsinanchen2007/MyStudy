### 解题思路
使用两个虚假头节点。
注意最后 rnode.next=null  否则会导致循环链表

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
    public ListNode partition(ListNode head, int x) {
        if(head==null||head.next==null){
            return head;
        }
        //思路  使用两个虚假头结点
        ListNode lnode=new ListNode(0);
        ListNode rnode=new ListNode(0);
        ListNode lhead=lnode;
        ListNode rhead=rnode;

        ListNode node=head;
        while(node!=null){
            if(node.val<x){
                lnode.next=node;
                lnode=lnode.next;
            }else{
                rnode.next=node;
                rnode=rnode.next;
            }
            node=node.next;
        }

        rnode.next=null;
        lnode.next=rhead.next;
        
        return lhead.next;

    }
}
```