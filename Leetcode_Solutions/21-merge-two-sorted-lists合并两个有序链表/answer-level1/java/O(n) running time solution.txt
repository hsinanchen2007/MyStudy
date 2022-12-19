### 解题思路
Build a new head to link the nodes by asc order
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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0); //new head for the merged list
        ListNode curr = head;
        
        if(l1 == null){
            return l2;
        }
        
        if(l2 == null){
            return l1;
        }
        
        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                curr.next = l1;
                curr = curr.next;
                l1 = l1.next;
            }
            else{
                curr.next = l2;
                curr = curr.next;
                l2 = l2.next;
            }
        }
        
        curr.next = l1 == null ? l2 : l1;
        return head.next;
    }
}
```