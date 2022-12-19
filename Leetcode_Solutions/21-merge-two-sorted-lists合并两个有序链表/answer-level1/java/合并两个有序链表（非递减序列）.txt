### 解题思路
设置一个最终链表的头节点，将l1和l2的节点依次比较确定哪一个尾插入最终链表。
当其中一个链表遍历完成时，则将另一个链表的剩余节点直接作为最终链表的尾节点即可。

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
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }

        ListNode newHead = new ListNode(0);
        ListNode p = newHead;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                p = p.next = l1;
                l1 = l1.next;
            } else {
                p = p.next = l2;
                l2 = l2.next;
            }
        }
        if (l1 != null) {
            p.next = l1;
        } else {
            p.next = l2;
        }
        return newHead.next;
    }
}
```