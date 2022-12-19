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
        ListNode dummyHead = new ListNode(-1) ;
        ListNode curNode = dummyHead ;
        ListNode i = l1 ;
        ListNode j = l2 ;
        while (i !=null && j !=null) {
            while (i !=null && j !=null && i.val <= j.val) {
                curNode.next = i ;
                curNode = curNode.next ;
                i = i.next ;
            }
            while (i !=null && j !=null && i.val >= j.val) {
                curNode.next = j ;
                curNode = curNode.next ;
                j = j.next ;
            }         
        }

        if (i != null) 
            curNode.next = i ;
        
        if (j != null)
            curNode.next = j ;
        
        return dummyHead.next ;
    }
}
```