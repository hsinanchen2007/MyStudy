**思路：** 可以通过set存储一个链表的值，然后遍历另外一个链表的节点，看是否存在于Set中。
```
public ListNode GetIntersectionNode(ListNode headA, ListNode headB)
        {
            var set = new HashSet<ListNode>();
            while (headA != null)
            {
                set.Add(headA);
                headA = headA.next;
            }

            while (headB != null)
            {
                if (set.Contains(headB))
                {
                    return headB;
                }

                headB = headB.next;
            }

            return null;
        }
```
**思路2：** 双指针法
```
public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
       if (headA == null || headB == null)
            {
                return null;
            }
            //不要在head上直接操作
            ListNode pA = headA;
            ListNode pB = headB;
            while (pA != pB)
            {
                pA = pA == null ? headB : pA.next;
                pB = pB == null ? headA : pB.next;
            }
            return pA;
    }
```
**注：** 不要在head上直接操作
