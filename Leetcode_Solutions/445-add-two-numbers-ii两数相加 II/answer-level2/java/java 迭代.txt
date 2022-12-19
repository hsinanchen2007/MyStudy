 1. 先反转两个链表
 2. 从前往后一次相加，保存在一个新的链表中
 3. 把较长的链表继续相加添加到新的链表后面，t保存进位信息
 4. 若链表所有节点相加完t仍有进位，添加新的节点再尾部即可
 5. 反转新的链表



public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode first = reverseList(l1);
        ListNode second = reverseList(l2);

        ListNode p1 = first;
        ListNode p2 = second;
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        int t = 0;
        while (p1 != null && p2 != null) {

            int temp = p1.val + p2.val + t;
            t = temp / 10;
            p1 = p1.next;
            p2 = p2.next;

            ListNode listNode = new ListNode(temp % 10);

            cur.next = listNode;
            cur = cur.next;

        }

        while (p1 != null) {
            int temp1 = p1.val + t;
            t = temp1 / 10;
            cur.next = new ListNode(temp1 % 10);
            cur = cur.next;
            p1 = p1.next;

        }
        while (p2 != null) {
            int temp1 = p2.val + t;
            t = temp1 / 10;
            cur.next = new ListNode(temp1 % 10);
            cur = cur.next;
            p2 = p2.next;

        }
        if (p1 == null && p2 == null & t == 1)
            cur.next = new ListNode(t);

        return reverseList(dummy.next);


    }

    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        while (cur != null) {
            ListNode temp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }