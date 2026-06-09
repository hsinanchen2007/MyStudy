### 解题思路
参考 leetcode1 9. 删除链表的倒数第N个节点
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
    public ListNode getKthFromEnd(ListNode head, int k) {
        if(head==null){
            return head;
        }
      ListNode ahead=  new ListNode(-1);
      ahead.next=head;
       ListNode slow=ahead;
       ListNode fast=ahead;
       while(k>0){
         fast=fast.next;
         k--;
       }
       if(fast==slow){
           return fast;
       }
       while(fast!=null){
           slow=slow.next;
           fast=fast.next;
       }
       return slow;
    }
}
```