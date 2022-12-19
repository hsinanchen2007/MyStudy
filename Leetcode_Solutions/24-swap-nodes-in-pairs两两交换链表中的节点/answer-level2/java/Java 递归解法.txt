```
// 递归解法
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        swap(head);
        return head;
    }
    
    private void swap(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }
        head.val = head.val ^ head.next.val;
        head.next.val = head.next.val ^ head.val;
        head.val = head.val ^ head.next.val;
        swap(head.next.next);
    }
}
```