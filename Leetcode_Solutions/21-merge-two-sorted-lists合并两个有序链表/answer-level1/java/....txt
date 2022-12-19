### 解题思路

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
        // 头指节点
        ListNode head = new ListNode(0);
        // 前一个结点
        ListNode pre = head;
        int min;
        
        while (l1 != null && l2 != null) {
            // 将小结点的接在结果链表的后面同时该节点后移
            if (l1.val < l2.val) {
                pre.next = l1;
                l1 = l1.next;
            } else {
                pre.next = l2;
                l2 = l2.next;
            }
            // 重置前一个结点
            pre = pre.next;
        }
        
        // l1有剩（应为原来是有序所以直接接上去）
        if (l1 != null) {
            pre.next = l1;
        } else {
            // l2有剩
            pre.next = l2;
        }
        
        return head.next;
    }
}
```