整体思路：
1. 检测有没有环，使用快慢指针slow和fast（一次走两步）；
2. 找位置，当找到环之后，slow从head出发，fast从相遇点出发，一次都走一步，再次相遇为环的入口点

证明为何第二步的方法能够找到入口点：
令： m 表示从head到入口的距离， d表示入口到相遇点的距离, r表示环的长度，ls表示slow走的长度，lf表示fast走的长度
有： ls = m + d, lf = m + d + n * r (n为正整数)， lf = 2 * ls
则： m + d + n * r = 2 * (m + d)
则： m = n * r - d， n >= 1
1. 当n=1时，m = r - d, 即”head到入口的距离（m）“等于”相遇点到入口的距离(r - d)“， 使用第二步方法能找到入口点；
2. 当n=2时，m = 2 * r - d, 等价于： m = (r - d) + r, 即”head到入口的距离（m）“等于”相遇点到入口的距离（r - d）加环长度“， 使用第二步方法会让fast指针多走一个环的长度，然后slow和fast还会相遇在环入口
3. 当n>2时，同理。

故： 上述方法正确



```
    // 先检测有没有环； 然后找位置
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }
        ListNode slow = head, fast = head;        
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            // 此处如果用if (slow != null && fast != null && slow.val == fast.val) 会超出时间限制
            if (slow == fast) {
                break;
            }
        }
        if (fast == null || fast.next == null) {
            return null;
        }

        // slow从head开始，fast从相遇点开始，一步一步走再次相遇即为环入口
        slow = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }
```