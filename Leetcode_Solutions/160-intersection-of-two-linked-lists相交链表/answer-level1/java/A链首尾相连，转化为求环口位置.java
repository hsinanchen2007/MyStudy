求A、B链表的交点，将A链首尾相连，若A、B有交点，即相当于B链有环，此题转化为求B链环口位置。
求环口位置，p1指向B链头，在B链上走快慢指针，快慢指针在环上的相遇点p2，p1、p2到环口等距，p1,p2一起向后移动，p1和p2的相遇点即为环口--链表相交点
```
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(null == headA || null == headB){
            return null;
        }
        ListNode l1 = headA;
        //把一个链表首尾相连，找环的入口
        while(null != headA.next){
            headA = headA.next;
        }
        headA.next = l1;//将A首尾相连
        
        //在B上走快慢指针
        ListNode slow = headB;
        ListNode fast = headB;
        ListNode p1 = headB;
        ListNode p2 = headB;
        while(null != fast && null != fast.next){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast){
                p2 = slow;//p2指向快慢指针相遇点
                while(p1 != p2){//p1 p2到环口等距，p1和p2的相遇点即为环口--链表相交点
                    p1 = p1.next;
                    p2 = p2.next;
                }
                headA.next = null;//将A链拆开
                return p1;
            }
        }
        headA.next = null;
        return null;
    }
}
```
