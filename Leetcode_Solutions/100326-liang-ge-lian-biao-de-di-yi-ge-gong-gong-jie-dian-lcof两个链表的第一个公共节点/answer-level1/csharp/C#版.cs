```csharp
public ListNode GetIntersectionNode(ListNode headA, ListNode headB) 
{
        if (headA == null || headB == null)
            return null;
        ListNode pA = headA, pB = headB;
        while (pA != pB)
        {
            // 谁先到null, 谁就是短的那条,
            // 1. 将短的那条指向另一条头结点
            // 此时, 长的链表到尾部的距离就是两条链表的个数差
            // 2. 长的链表走完后指向短的链表头节点
            // 此时, 两条链表个数相同
            // 3. 依次比较值, 看哪个节点相交
            pA = pA == null ? headB : pA.next;
            pB = pB == null ? headA : pB.next;
        }

        return pA;
}
```
