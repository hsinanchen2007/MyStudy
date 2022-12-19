思路：
1：遍历两个链表分别记录链表长度
2：长链表的指针往后移动，直到两个链表长度一致
3：两个链表的指针同时后移，直到遇到相同节点
```
public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null){
            return null;
        }
        ListNode curA = headA;
        ListNode curB = headB;
        int lengthA = 0, lengthB = 0;
        while (curA != null){
            lengthA++;
            curA = curA.next;
        }
        while (curB != null){
            lengthB++;
            curB = curB.next;
        }
        curA = headA;
        curB = headB;
        for (int i=0; i<lengthA-lengthB; i++){
            curA = curA.next;
        }
        for (int i=0; i<lengthB-lengthA; i++){
            curB = curB.next;
        }
        while (curA != curB){
            curA = curA.next;
            curB = curB.next;
        }
        return curA;
    }
```
