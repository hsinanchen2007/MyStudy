```
public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        int lenA = 0, lenB = 0;
        ListNode pA = headA, pB = headB;
        while (pA != null) {
            pA = pA.next;
            ++lenA;
        }
        while (pB != null) {
            pB = pB.next;
            ++lenB;
        }
        //让长的链表的指针先走（两链表长度的差值步）
        pA = headA;
        pB = headB;
        if (lenA > lenB) {
            for (int i = 0; i < (lenA - lenB); ++i)
                pA = pA.next;
        }
        if (lenB > lenA) {
            for (int i = 0; i < lenB - lenA; ++i)
                pB = pB.next;
        }
        while (pA != pB) {
            pA = pA.next;
            pB = pB.next;
        }
        return pA;
    }
```
