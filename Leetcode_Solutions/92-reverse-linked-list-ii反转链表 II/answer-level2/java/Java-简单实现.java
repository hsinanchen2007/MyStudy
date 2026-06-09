简单的通过指针移动 找到 待翻转的 区域，然后对该区域做翻转，最后将 pre/next 与之连起来 就可以了。


```
class Solution {

    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || head.next == null) {
            return head;
        }
        if (m == n) {
            return head;
        }

        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode pre = dummy;
        ListNode end = dummy;
        for (int i = 1; i <= n; i++) {
            if (i < m) {
                pre = pre.next;
            }
            end = end.next;
        }

        ListNode start = pre.next;
        ListNode next = end.next;
        end.next = null;

        pre.next = reverse(start);
        start.next = next;
        return dummy.next;
    }

    private ListNode reverse(ListNode head) {
        ListNode pre = null;
        ListNode p = head;
        while (p != null) {
            ListNode next = p.next;
            p.next = pre;
            pre = p;
            p = next;
        }
        return pre;
    }
}
```

提交结果：
![image.png](https://pic.leetcode-cn.com/3b123c2b1b93eb3bcb46d9fe0668c840c47ab222eb6663e131716fd887282e74-image.png)