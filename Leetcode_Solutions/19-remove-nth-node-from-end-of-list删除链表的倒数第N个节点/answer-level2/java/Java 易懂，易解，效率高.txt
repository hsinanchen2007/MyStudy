1. 关注代码的规范性、完整性、鲁棒性。
2. 提供两种方法：
**方法 1：** 定义一个新链表指向 `head`，在新链表里进行 Operation，定义了 `fast` 和 `slow` 两个指针同时指向新链表的头结点，先让 `fast` 走 $n$ 步，然后 `fast` 和 `slow` 一起往下走，直到 `fast` 走到链表的最后一个节点，`slow` 指向的就是要删除节点的前一个结点；
**方法 2：** 在原先链表进行 Operation，定义一个 temp 指针从链表头遍历，每次 -1，遍历完后分情况讨论：当 n > 0，说明链表中根本没有倒数第 K 个节点，当 n = 0，说明倒数第 K 个节点就是链表的头元素，返回 `head.next`，当 $n < 0$，如果 $n = -1$，那么现在所指的就是待删除节点的前一个位置，当 $n < -1$，遍历当 $n = -1$ 意味着到达了待删除节点的前一个位置；
3. 完结。

##### 方法 1：常规 Operation
```java
        public ListNode removeNthFromEnd(ListNode head, int n) {
            if (head == null || n < 1)
                return head;

            ListNode res = new ListNode(-1);
            res.next = head;
            ListNode slow = res;
            ListNode fast = res;
            for (int i = 0; i < n; i++) {
                fast = fast.next;
            }
            if (fast == null) // n 无效
                return head;

            while (fast.next != null) {
                fast = fast.next;
                slow = slow.next;
            }
            slow.next = slow.next.next;
            return res.next;
        }
```
##### 方法 2：在原链表 Operation
```java
        public ListNode removeNthFromEnd(ListNode head, int n) {
            if (head == null || n < 1)
                return head;
            
            ListNode tmp = head;
            while (tmp != null) {
                n--;
                tmp = tmp.next;
            }
            if(n > 0 )
                return head;
            if(n == 0)
                return head.next;
            
            tmp = head;
            while (n < -1) {
                n++;
                tmp = tmp.next;
            }
            tmp.next = tmp.next.next;
            return head;
        }
```