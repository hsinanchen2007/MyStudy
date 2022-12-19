### 解题思路
用时1ms，击败81.81%
注意相同值时链表不能断链

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
        ListNode listNode = new ListNode(0);
        ListNode root = listNode;
        while ( l1 != null && l2 != null){
            if (l1.val < l2.val){
                listNode.next = l1;
                l1 = l1.next;
                listNode = listNode.next;
            }else if(l1.val > l2.val){
                listNode.next = l2;
                l2 = l2.next;
                listNode = listNode.next;
            }else {
                listNode.next = l1;
                l1 = l1.next;
                listNode.next.next = l2;
                l2 = l2.next;
                listNode = listNode.next.next;
            }
        }
        if (l1 != null){
            listNode.next = l1;
        }else if (l2 != null){
            listNode.next = l2;
        }
        return root.next;
    }
}
```