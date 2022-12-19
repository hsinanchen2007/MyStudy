### 解题思路
此处撰写解题思路

1. 通过快慢指针，找到中间节点；
2. 上半部分快指针走完前，前半部分元素进行压栈；
3. 慢指针遍历下半部分时每个元素与栈顶元素对比，相等则出栈，不相等则返回false。
4. 最后栈内为空则为回文数

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        Stack<Integer> stack = new Stack<>();
        // 没有元素或只有一个元素时直接返回
        if (fast == null || fast.next == null) {
            return true;
        }
        // 上半部分压栈
        while (fast != null && fast.next != null) {
            stack.push(slow.val);
            fast = fast.next.next;
            slow = slow.next;
        }
        // 下半部分出栈比较
        while (slow != null) {
            // fast为null表示链表长度是奇数
            if (fast == null) {
                if (slow.val == stack.peek()) {
                    stack.pop();
                    slow = slow.next;
                } else {
                    return false;
                }
            } else {
                // 当链表是奇数时，忽略最中间的元素
                slow = slow.next;
                fast = null;
            }
        }
        return stack.empty();
    }
}
```