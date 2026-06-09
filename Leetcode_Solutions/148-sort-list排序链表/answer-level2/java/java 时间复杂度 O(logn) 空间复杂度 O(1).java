虽然最后时间没有超过很多，但是这是由于结果池已经被很多空间复杂度O(logn)级别的结果污染了，不代表这个方法是不对的
```
class Solution {
     public ListNode sortList(ListNode head) {
        int n = 0;
        ListNode tempHead = new ListNode(0);
        tempHead.next = head;
        while (head != null) {
            head = head.next;
            n++;
        }
        for (int step = 1; step < n; step = step << 1) {
            ListNode prev = tempHead;
            ListNode cur = tempHead.next;
            while (cur != null) {
                ListNode left = cur;
                ListNode right = split(left, step);
                cur = split(right, step);
                prev = merge(prev, left, right);
            }
        }
        return tempHead.next;
    }

    private ListNode split(ListNode head, int step) {
        if (head == null) {
            return null;
        }
        for (int i = 1; head.next != null && i < step; i++) {
            head = head.next;
        }

        ListNode right = head.next;
        head.next = null;
        return right;
    }

    private ListNode merge(ListNode head, ListNode left, ListNode right) {
        while (left != null && right != null) {
            if (left.val <= right.val) {
                head.next = left;
                left = left.next;
            } else{
                head.next = right;
                right = right.next;
            }
            head = head.next;
        }
        head.next = left == null ? right : left;
        while (head.next != null) {
            head = head.next;
        }
        return head;
    }
}
```
