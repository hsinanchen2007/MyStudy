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
    public ListNode deleteNode(ListNode head, int val) {
        if(head.val==val){
            return head.next;
        }
        if(head==null){
            return null;
        }
        ListNode start =head;
        ListNode pre=head;
        while(true){
            start=start.next;
            if(start.val==val){
                pre.next=start.next;
                return head;
            }
            pre=pre.next;
            
        }
        
        
    }
}
```