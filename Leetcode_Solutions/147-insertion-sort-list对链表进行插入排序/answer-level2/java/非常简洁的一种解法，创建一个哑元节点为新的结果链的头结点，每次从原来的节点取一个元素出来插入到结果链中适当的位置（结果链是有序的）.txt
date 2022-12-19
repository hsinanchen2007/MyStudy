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
    public ListNode insertionSortList(ListNode head) {
        if(head == null){
            return head;
        }
        ListNode dummy = new ListNode(0);
        ListNode current = head;

        while(current != null){
            ListNode node = dummy;
            while(node.next != null && node.next.val < current.val)
                node = node.next;
            ListNode temp = current.next;
            current.next = node.next;
            node.next = current;
            current = temp;
        }

        return dummy.next;
    }
}
```