### 解题思路
将l2中的节点插入l1中，最后返回即可

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
        // 若l1为空，则直接返回l2
        if (l1 == null) {
            return l2;
        }
        // 设置l1的前驱节点
        ListNode pre = new ListNode();
        pre.next = l1;
        // 设置head用于返回，令其等于pre是为了防止在l1节点前插入了新节点
        ListNode head = pre;
        // 遍历两链表，并将l2链表中的节点一次插入l1中
        while (l1 != null && l2 != null) {
            if (l1.val > l2.val) {
                pre.next = l2;
                pre = l2;
                l2 = l2.next;
                pre.next = l1;
            }
            else {
                pre = l1;
                l1 = l1.next;
            }
        }
        // 若l2仍有剩余节点，则全部插入l1后面
        if (l2 != null)
            pre.next = l2;
        // 返回
        return head.next;
    }
}
```