执行用时:3 ms,在所有 Java 提交中击败了99.59%的用户
内存消耗:43.3 MB,在所有 Java 提交中击败了89.01%的用户
```
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return addTwoNumbers(l1, l2, null);
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2, ListNode prev) {
        ListNode next1 = null;
        ListNode next2 = null;
        int val1 = 0;
        int val2 = 0;
        if (l1 != null) {
            val1 = l1.val;
            next1 = l1.next;
        }
        if (l2 != null) {
            val2 = l2.val;
            next2 = l2.next;
        }
        ListNode newNode = new ListNode(val1 + val2);
        if (prev != null) {
            if (prev.val >= 10) {
                prev.val %= 10;
                newNode.val += 1;
            }
        }
        if (next1 != null || next2 != null) {
            newNode.next = addTwoNumbers(next1, next2, newNode);
        } else if (newNode.val >= 10) {
            newNode.next = addTwoNumbers(next1, next2, newNode);
        }
        return newNode;
    }
}
```
