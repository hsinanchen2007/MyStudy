```java
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // 先让快指针向后走n步，然后快慢指针一起走
        if (head == null) return head;
        ListNode fast = head;
        // 先让快指针走n步就可能出现，不够n步的情况，需要注意
        for (int i = 0;i < n;i ++) {
            // 如果快指针刚好走完N步，说明这个N等于链表的长度，返回头结点
            if (i == n - 1 && fast == null) {
                return head;
            } else if (fast != null) {
                fast = fast.next;
            // 说明链表的长度不够长,返回空即可
            } else {
                return null;
            }
        }
        // 现在从头和从fast所在的位置，每次往后一步，
        // fast为空的时候，所在的那个节点就是倒数第K个节点
        // 因为要删除节点，所以我们需要知道被删除节点的前一个节点，使用prev来记录
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode prev = dummy;
        // 每次往后走一步，直到快指针为空
        while (fast != null) {
            prev = prev.next;
            head = head.next;
            fast = fast.next;
        }
        // 删除倒数第N个节点
        prev.next = head.next;
        head.next = null;
        return dummy.next;
    }
}
```