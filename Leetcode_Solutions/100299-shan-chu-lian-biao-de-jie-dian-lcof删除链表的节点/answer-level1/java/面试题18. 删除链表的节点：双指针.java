### 解题思路
比较简单

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
    public ListNode deleteNode(ListNode head, int val) {
        if(head.val==val){
            return head.next;
        }
        ListNode pre=head;
        ListNode cur=head.next;
        while(cur!=null){
            if(cur.val==val){
                pre.next=cur.next;
            }
            pre=cur;
            cur=cur.next;
        }
        return head;
    }
}
```