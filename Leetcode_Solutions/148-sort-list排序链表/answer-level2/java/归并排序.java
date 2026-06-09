归并排序，注释写的很清晰
```gradle
class Solution {
    public ListNode sortList(ListNode head) {

        if (head == null || head.next == null) {
            return head;
        }

        // 快慢指针找到中间节点
        ListNode fast = head;
        ListNode slow = head;
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        // 前半截
        ListNode left = head;
        // 后半截
        ListNode right = slow.next;
        // 截断
        slow.next = null;

        // 对左子链右子链分别排序
        ListNode newLeftHead = sortList(left);
        ListNode newRightHead = sortList(right);
        // 合并左右子链
        ListNode newHead = merge(newLeftHead, newRightHead);

        return newHead;
    }
    
    /**
     * 合并两个有序链表，返回新链表的链头
     * @param left
     * @param right
     * @return
     */
    public ListNode merge(ListNode left, ListNode right) {
        // 哨兵节点
        ListNode sentinal = new ListNode(Integer.MIN_VALUE);
        ListNode head = sentinal;
        while (left != null && right != null) {
            if (left.val <= right.val) {
                head.next = left;
                left = left.next;
            } else {
                head.next = right;
                right = right.next;
            }
            head = head.next;
        }
        if (left != null) {
            head.next = left;
        }
        if (right != null) {
            head.next = right;
        }
        return sentinal.next;
    }
}
```