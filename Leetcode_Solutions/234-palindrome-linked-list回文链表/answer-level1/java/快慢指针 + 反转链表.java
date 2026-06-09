第一步：快慢指针找到中间节点
第二步：翻转后半段
第三步：对比

```java
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }

        // 快慢指针找到中点，最后 slow 会是中点
        ListNode slow = head;
        ListNode fast = head.next;
        ListNode temp = null;

        while (fast != null) {
            slow = slow.next;
            temp = fast.next;
            if (temp == null) {
                fast = null;
            } else {
                fast = temp.next;
            }
        }

        // 翻转 slow
        ListNode pre = null;
        ListNode current = slow;

        while(current != null) {
            temp = current.next;
            current.next = pre;
            pre = current;
            current = temp;
        }

        // 新的头节点就是 pre
        ListNode newHead = pre;

        while (newHead != null && head != null) {
            if (newHead.val == head.val) {
                newHead = newHead.next;
                head = head.next;
                continue;
            }
            return false;
        }

        return true;
    }
}
```