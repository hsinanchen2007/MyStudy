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
if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        ListNode head = null, tail = null, p;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                p = l1;
                l1 = l1.next;
            } else {
                p = l2;
                l2 = l2.next;
            }
            // 链表有没有创建成功了
            if (tail != null) {
                tail.next = p;
                tail = p;
            } else {
                head = tail = p;
            }
        }
        // 看看l1完了没有
        if (l1 != null) {
            tail.next = l1;
        }
        
        // 看看l2完了没有
        if (l2 != null) {
            tail.next = l2;
        }
        return head;
    }
}
```