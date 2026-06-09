先将链表反转，然后遍历节点，节点值为1时，加上对应的count，count每进行一次循环往左移一位
```
class Solution {
    public int getDecimalValue(ListNode head) {
        head = reverse(head);
        int result = 0;
        int count = 1;
        while (head != null) {
            if (head.val == 1) {
                result += count;
            }
            count <<= 1;
            head = head.next;
        }
        return result;
    }

    /**
     * 链表反转
     *
     * @param head
     * @return
     */
    private ListNode reverse(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}
```
