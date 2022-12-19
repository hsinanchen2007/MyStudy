1. O(n)时间复杂度和O(n)空间复杂度，只需要把链表遍历出来放到数组中，然后判断即可；
2. O(n)时间复杂度和O(1)空间复杂度, 可以先计算链表长度N，然后在N/2处反转链表，正向链表和反向链表分别对比，然后再将反向链表反转，挂在正向链表后边，保证原始链表不变。

注： 使用递归做不到O(1)空间复杂度，每递归一次都要维护局部变量，详见官方解读

```
    // 实现第2种方法
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }
        // 确定中间节点，使用快慢指针
        // 1. fast == null 则链表数量是偶数，slow是后半链表第一个元素；
        // 2. fast != null 则链表数量是奇数，fast是中间元素
        ListNode slow = head, fast = head;
        // 最后slow是中间节点，last是中间节点的上一个，用于拼接后半段
        ListNode last = head;
        while (fast != null && fast.next != null) {
            last = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        // 反转slow
        ListNode revHead = reverse2(slow);

        // 遍历正向和反向
        boolean res = true;
        ListNode p = head, q = revHead;
        while (p != null && q != null) {
            if (p.val != q.val) {
                res = false;
                break;
            }
            p = p.next;
            q = q.next;
        }
        // 反转revHead，接回原链表
        ListNode breakHead = reverse2(revHead);
        last.next = breakHead;
        return res;
    }

    // 看官方文档，使用递归做不到空间复杂度为O(1)，只能使用迭代的方式解决
    private ListNode reverse(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode tmp = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return tmp;
    }

    // 头插法
    private ListNode reverse2(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode p = head.next;
        head.next = null;
        while (p != null) {
            ListNode next = p.next;
            p.next = dummy.next;
            dummy.next = p;
            p = next;
        }
        return dummy.next;
    }
```