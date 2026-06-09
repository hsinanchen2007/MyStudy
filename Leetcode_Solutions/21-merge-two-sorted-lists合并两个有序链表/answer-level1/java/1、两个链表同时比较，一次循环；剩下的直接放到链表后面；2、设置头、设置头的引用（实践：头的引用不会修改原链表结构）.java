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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(-1);

        ListNode prev = head;
        while(l1 != null && l2 != null ){
            int val1 = l1.val;
            int val2 = l2.val;
            if(val1 > val2){
                prev.next = l2;
                l2 = l2.next;
            }else{
                prev.next = l1;
                l1 = l1.next;
            }
            prev = prev.next;
        }
        while(l1 != null ){
            prev.next = l1;
            l1 = l1.next;
            prev = prev.next;
        }    
        while(l2 != null ){
            prev.next = l2;
            l2 = l2.next;
            prev = prev.next;
        }  
        return head.next; 
    }
}
```