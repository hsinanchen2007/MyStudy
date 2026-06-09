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
        ListNode no = new ListNode(-1);
        ListNode head = no;
        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                no.next = l1;
                no = no.next;
                l1 = l1.next;
            }else{
               no.next = l2;
                no = no.next; 
                l2 = l2.next;
            }
        }
        if(l1 != null){
            no.next = l1;
        }else if(l2 != null){
            no.next = l2;
        }
        return head.next;
    }
}
```