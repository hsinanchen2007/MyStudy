### 解题思路
类似有序数组的归并，注意链表的coding

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
        ListNode result = new ListNode();
        ListNode res = result;
        while(l1 != null && l2 != null) {
            int value = l1.val < l2.val ? l1.val : l2.val;
            result.next = new ListNode(value);
            result = result.next;
            if (l1.val < l2.val) {
                l1 = l1.next;
            } else {
                l2 = l2.next;
            }
        }
        while (l1 != null) {
            result.next = new ListNode(l1.val);
            result = result.next;;
            l1 = l1.next;
        }
        while (l2 != null) {
            result.next = new ListNode(l2.val);
            result = result.next;
            l2 = l2.next;
        }
        return res.next;
    }
}
```