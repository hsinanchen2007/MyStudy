进阶中说不能翻转给进的链表

我们可以使用栈来达到链表翻转的效果，代码如下：
```java
    //输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
    //输出: 7 -> 8 -> 0 -> 7
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();
        while (l1 != null) {
            stack1.push(l1.val);
            l1 = l1.next;
        }
        while (l2 != null) {
            stack2.push(l2.val);
            l2 = l2.next;
        }
        // 进位
        int carry = 0;
        ListNode dummy = new ListNode(0);
        ListNode temp = dummy;
        while (stack1.size() > 0 || stack2.size() > 0) {
            int n1 = stack1.size() == 0 ? 0 : stack1.pop();
            int n2 = stack2.size() == 0 ? 0 : stack2.pop();
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            dummy.next = new ListNode(sum % 10);
            dummy = dummy.next;
        }
        // 如果最后进位了
        if (carry > 0) {
            dummy.next = new ListNode(carry);
        }
        return reverse(temp.next);
    }

    // 翻转链表
    private static ListNode reverse(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode last = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return last;
    }
```
