### 解题思路
   链表判断是否有环题的改进。当两个快慢指针相遇时，将其中快指针拉回表头，重新开始一步一步走，此时满指针也一步一步走，当他们再次相遇时的节点就是环的起点。

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head==null || head.next==null){
            return null;
        }
        ListNode node=head,pre=head;
        ListNode restart =null;
        while(pre!=null && node!=null){
            if(pre.next!=null){
                pre=pre.next.next;
                node = node.next;
                if(node==pre){
                   break;
                }
            }else{
                return null;
            }
        }
        if(pre==null || node==null){
            return null;
        }
        pre = head;
        while(pre!=null){
            if(node==pre){
                return node;
            }
            node=node.next;
            pre=pre.next;
        }
       return null; 
    }
}
```