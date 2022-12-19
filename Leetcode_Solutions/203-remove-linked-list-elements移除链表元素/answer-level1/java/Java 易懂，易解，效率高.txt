**1.关注代码的规范性、完整性、鲁棒性。
2.法1：找到第一个不为val的结点作为头结点,定义两个指针进行删除操作;
法2：定义一个新链表指向head结点,进行删除操作;
法3：递归的从后往前进行删除操作;
3.完结。**

        // 原链表Operation
        public ListNode removeElements(ListNode head, int val) {
            while (head != null) {
                if (head.val != val)
                    break;
                head = head.next;
            }
            ListNode pre = head;
            ListNode cur = head;
            while (cur != null) {
                if (cur.val == val)
                    pre.next = cur.next;
                else
                    pre = cur;
                cur = cur.next;
            }
            return head;
        }

新链表上操作

            // 新链表Operation
            public ListNode removeElements(ListNode head, int val) {
                if (head == null)
                    return head;
                ListNode pre = new ListNode(-1);
                pre.next = head;
                ListNode cur = pre;
                while (cur.next != null) {
                    if (cur.next.val == val) {
                        cur.next = cur.next.next;
                    } else {
                        cur = cur.next;
                    }
                }
                return pre.next;
            }

递归

        public ListNode removeElements(ListNode head, int val) {
            if (head == null)
                return null;
            head.next = removeElements(head.next, val);
            if (head.val == val) {
                return head.next;
            } else {
                return head;
            }
        }