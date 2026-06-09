**1.这道题本质上是一个两数相加的问题，意思是两个链表的数先取反,再相加,再将结果取反的一个过程,这个思路可以做题,但是比较麻烦,效率也不高,如果仔细观察的话,其实可以将这两个链表的数字分别相加,向后进位构造一个新的链表即可;
2.carry保存进位数,最后如果carry如果为1,说明还应该要有一个节点;
3.完结。**


        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode head = new ListNode(0);
            ListNode res = head;
            int carry = 0;
            while (l1 != null || l2 != null) {
                int num1 = l1 != null ? l1.val : 0;
                int num2 = l2 != null ? l2.val : 0;
                int temp = num1 + num2 + carry;
                carry = temp / 10;
                res.next = new ListNode(temp % 10);
                res = res.next;
                if (l1 != null)
                    l1 = l1.next;
                if (l2 != null)
                    l2 = l2.next;
            }
            if (carry == 1)
                res.next = new ListNode(1);
            return head.next;
        }