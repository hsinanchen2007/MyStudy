**解法一：**利用快慢指针和迭代。

```java
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0), slow = dummy, fast = dummy;
        dummy.next = head;
        while (fast != null) {
            for (int i = 1; i <= k; i++) {
                fast = fast.next;
                if (fast == null) return dummy.next;
            }
            ListNode next_head = fast.next;
            ListNode tail = slow.next;     
            fast.next = null;
            slow.next = reverseOne(slow.next);
            tail.next = next_head;       
            fast = tail;
            slow = tail;    
        }
        return dummy.next;
    }

    public ListNode reverseOne(ListNode head) {
        ListNode pre = null, cur = head;
        while (cur != null) {
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
}
```

**解法二：**递归。

```java
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode tail = head, pre = null, cur = head;
        for (int i = 1; i <= k; i++) {
            if (cur == null) return head;
            cur = cur.next;
        }
        cur = head;
        for (int i = 1; i <= k; i++) {
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        tail.next = reverseKGroup(cur, k);
        return pre;
    }
}
```

**解法三：**利用栈。

```java
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        Deque<ListNode> stack = new LinkedList<>();
        ListNode dummy = new ListNode(0), pre = dummy, cur = head;
        while (true) {
            for (int i = 1; i <=k; i++) {
                if (cur == null) return dummy.next;
                stack.push(cur);
                cur = cur.next;
            }
            while (!stack.isEmpty()) {
                pre.next = stack.pop();
                pre = pre.next;
            }
            pre.next = cur;
        }
    }
}
```

