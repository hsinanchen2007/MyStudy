官方解答3 太难想到了，还是下面的方法最容易理解：先把节点多的链表从头删、直到和短的一样长，再同时双指针往后走、遇到的第一个交点就是结果

```
   public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        // 把长的链表从头删除节点，直到等于短的链表长度
        int sizea = getSize(headA);
        int sizeb = getSize(headB);
        if (sizea < sizeb) {
            for (int i = 0; i < sizeb - sizea; i++) {
                headB = headB.next;
            }
        } else {
            for (int i = 0; i < sizea - sizeb; i++) {
                headA = headA.next;
            }
        }

        // 双指针同时走，相遇就是交点
        while (headA != null && headB != null && headA != headB) {
            headA = headA.next;
            headB = headB.next;
        }

        if (headA != null && headB != null) {
            return headA;
        } else {
            return null;
        }
    }

    private int getSize(ListNode head) {
        int count = 0;
        while (head != null) {
            head = head.next;
            count++;
        }
        return count;
    }
```

```
