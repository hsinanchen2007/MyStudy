- 先快慢指针取中点
- 然后递归后半部分，在“归”的时候（逆序）和前半部分（正序）判断
```Java
class Solution {
    private ListNode head;
    public boolean isPalindrome(ListNode head) {
        this.head = head;
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return recusion(slow);
    }
    private boolean recusion(ListNode node) {
        if (node == null)
            return true;
        boolean ret = recusion(node.next);
        boolean isEq = (node.val == head.val);
        head = head.next;
        return ret && isEq;
    }
}
```
