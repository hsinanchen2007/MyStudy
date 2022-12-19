```java
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        // A 长度
        int lengthA = 0;
        ListNode myHeadA = headA;
        for (; myHeadA != null; myHeadA = myHeadA.next, lengthA++);
        // B 长度
        int lengthB = 0;
        ListNode myHeadB = headB;
        for (; myHeadB != null; myHeadB = myHeadB.next, lengthB++);
        myHeadA = headA;
        myHeadB = headB;
        // B 比 A 长
        int i;
        if (lengthB > lengthA) {
            for (i = lengthB - lengthA; i > 0; i--) {
                myHeadB = myHeadB.next;
            }
        }
        // A 比 B 长
        else if (lengthA > lengthB) {
            for (i = lengthA - lengthB; i > 0; i--) {
                myHeadA = myHeadA.next;
            }
        }
        // 现在二者一样长
        for (; myHeadA != null; myHeadA = myHeadA.next, myHeadB = myHeadB.next) {
            if (myHeadA == myHeadB) {
                return myHeadA;
            }
        }
        return null;
    }
}
```