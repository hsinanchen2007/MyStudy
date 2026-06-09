**1.关注代码的规范性、完整性、鲁棒性。
2.写一个反转链表的方法,要不会显得代码复用性很低;
3.反转l1,l2链表,遍历两条链表每个节点分别相加,向后进位,在生成新结点的同时让指针反向指向前一个节点,最后返回res即可,(当然也可以最后反向相加的结果链表);
4.完结。**


    //   9 3 7 		7 3 9
    //     6 3 		3 6
    // 1 0 0 0 		0←0←0←1
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode rev1 = reverseList(l1);
            ListNode rev2 = reverseList(l2);

            ListNode res = null;
            ListNode pre = null;
            int carry = 0;
            while (rev1 != null || rev2 != null) {
                int num1 = rev1 != null ? rev1.val : 0;
                int num2 = rev2 != null ? rev2.val : 0;
                int temp = num1 + num2 + carry;
                carry = temp / 10;
                pre = res;
                res = new ListNode(temp % 10);
                res.next = pre;
                rev1 = rev1 != null ? rev1.next : null;
                rev2 = rev2 != null ? rev2.next : null;
            }
            if (carry == 1) {
                pre = res;
                res = new ListNode(1);
                res.next = pre;
            }
            return res;
        }

        public static ListNode reverseList(ListNode cur) {
            ListNode rev = null;
            while (cur != null) {
                ListNode temp = cur.next;
                cur.next = rev;
                rev = cur;
                cur = temp;
            }
            return rev;
        }