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
        ListNode aNode = head;
        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                aNode.next = l1;
                l1 = l1.next;
                aNode = aNode.next;
            }else{
                aNode.next = l2;
                l2 = l2.next;
                aNode = aNode.next;
            }
        }
        if(l1 == null){
            aNode.next = l2;
        }else if(l2 == null){
            aNode.next = l1;
        }
        return head.next;
    }
}
```