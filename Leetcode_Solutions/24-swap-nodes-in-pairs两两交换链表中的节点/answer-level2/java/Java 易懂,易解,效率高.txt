**1.详细介绍一下递归的思路;
2.递归和栈处理问题类似,先把问题从前往后收集起来,然后再从后往前处理每一个问题;
3.两两交换链表结点,先处理最后两个或一个节点,然后再从后往前处理每一对节点;
4.先创建一个next临时结点保存head的下一个结点,然后让head指向下下一个节点,最后让 next节点指向head结点;
5.此题只有处理完后面的结点才可处理前面的结点,画图更容易理解;
6.完结。**

        public ListNode swapPairs(ListNode head) {
            if (head == null || head.next == null)
                return head;

            // 三个节点顺序:head, next, swapPairs(next.next)
            ListNode next = head.next;
            head.next = swapPairs(next.next);
            next.next = head;
            return next;
        }