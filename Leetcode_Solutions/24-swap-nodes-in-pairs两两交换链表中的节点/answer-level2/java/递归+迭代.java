## 思路：将奇偶数位置调换

# 迭代
```
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode travel = dummy;
        while (travel != null && travel.next != null && travel.next.next != null) {
            ListNode tmp = travel.next;
            travel.next = tmp.next;
            tmp.next = travel.next.next;
            travel.next.next = tmp;
            travel = travel.next.next;
        }
        return dummy.next;
    }
}
```
时间复杂度: O(n), 空间复杂度: O(1).
# 递归
```
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        swapPairsHelper(dummy);
        return dummy.next;
    }
    private void swapPairsHelper(ListNode head) {
        if (head == null || head.next == null || head.next.next == null)
            return;
        swapPairsHelper(head.next.next);
        ListNode tmp = head.next.next;
        head.next.next = tmp.next;
        tmp.next = head.next;
        head.next = tmp;
    }
}
```
时间复杂度: O(n), 空间复杂度: O(n).