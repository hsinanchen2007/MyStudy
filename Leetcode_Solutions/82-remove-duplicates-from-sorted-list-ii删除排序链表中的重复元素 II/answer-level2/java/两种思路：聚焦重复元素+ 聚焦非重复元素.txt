这里提供两种解法。两种解法都使用一个额外的指针来构建新的链表。区别在于聚焦点不一样。解法1的思路聚焦于非重复元素，即应当保留的元素，解法2聚焦于重复元素，探测到重复元素直接跳过。

水平有限，敬请批评指正。

```
public class Topic082 {
    public static class Solution1 {
        public ListNode deleteDuplicates(ListNode head) {
            // 哑节点
            ListNode dumbHead = new ListNode(0);
            dumbHead.next = head;
            ListNode newHead = dumbHead;
            ListNode prev = null;
            ListNode cur = head;
            while (cur != null) {
                // 当且仅当当前节点的值与前驱节点和后驱节点都不同时，应当保留当前节点
                if ((prev == null || cur.val != prev.val) && (cur.next == null || cur.val != cur.next.val)) {
                    newHead.next = cur;
                    newHead = cur;
                }
                prev = cur;
                cur = cur.next;
            }
            newHead.next = null;
            return dumbHead.next;
        }
    }

    public static class Solution2 {
        public ListNode deleteDuplicates(ListNode head) {
            // 哑节点
            ListNode dumbHead = new ListNode(0);
            dumbHead.next = head;
            ListNode newHead = dumbHead;
            ListNode cur = head;
            while (cur != null) {
                // 直接跳过重复节点
                if (cur.next != null && cur.next.val == cur.val) {
                    while (cur.next != null && cur.next.val == cur.val) {
                        cur = cur.next;
                    }
                    cur = cur.next;
                } else {
                    newHead.next = cur;
                    newHead = cur;
                    cur = cur.next;
                }
            }
            newHead.next = null;
            return dumbHead.next;
        }
    }
}

```
