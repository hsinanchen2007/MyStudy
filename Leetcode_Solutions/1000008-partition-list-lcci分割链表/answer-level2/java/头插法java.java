### 解题思路
使用头插法即可，其中开始循环的节点为head.next，因为head不用判断

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
        if(head==null) return null;
        ListNode dummy=new ListNode(-1);
        dummy.next=head;
        ListNode prev=head;
        head=head.next;
        while(head!=null){
            if(head.val<x){
                prev.next=head.next;
                head.next=dummy.next;
                dummy.next=head;
                head=prev.next;
            }else{
                prev=prev.next;
                head=head.next;
            }
        }
        return dummy.next;
    }
}
```