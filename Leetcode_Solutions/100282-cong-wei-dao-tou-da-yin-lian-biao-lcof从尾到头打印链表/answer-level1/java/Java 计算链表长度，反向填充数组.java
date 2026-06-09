用一个指针遍历链表长度得出数组容量
然后从数组的最后一位开始填充
`public int[] reversePrint(ListNode head) {
        ListNode p1 = head;
        int size = 0;
        while (p1 != null) {
            size++;
            p1 = p1.next;
        }
        int[] ints = new int[size];
        while (head != null) {
            ints[--size] = head.val;
            head = head.next;
        }
        return ints;
    }`