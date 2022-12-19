### 解题思路
本题是我做的链表第一题

- 反转链表关键就在于定义指针**保护链表不断链**，然后**找准前驱和后继**

- 通过`while`循环不断遍历整个链表，尤其到最后，注意**返回的是哪个指针所指结点**

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
    public ListNode reverseList(ListNode head) {
        // 一开始定义前驱结点为 null
        ListNode pre = null;
        // 定义 cur 指针指向 head 结点
        ListNode cur = head;
        while (cur != null) {
            // 如果 cur 不为 null 再定义 next 指针指向 cur 的后继结点
            ListNode next = cur.next;
            // cur 的后继指向前面，pre 和 cur 分别往后移动
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
}
```