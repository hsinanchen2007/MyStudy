虽然时间复杂度为O(n^2)，但是还是很好理解滴
1. 求链表长度len
2. 最后一个元素往前面放
3. 倒数第二个元素next域置空
4. 循环 步骤2-3 （k % len）次，因为循环k次链表又复原了
```
        public ListNode rotateRight(ListNode head, int k) {
            if (head == null || head.next == null) {
                return head;
            }
            ListNode p = head;
            int len = 0;
            while (p != null) {
                p = p.next;
                len++;
            }
            int loop = k % len;
            System.out.println(len);
            for (int i = 0; i < loop; i++) {
                ListNode last = head.next;
                ListNode secondLast = head;
                while (last.next != null) {
                    secondLast = secondLast.next;
                    last = last.next;
                }
                last.next = head;
                head = last;
                secondLast.next = null;
            }
            return head;
        }
```
