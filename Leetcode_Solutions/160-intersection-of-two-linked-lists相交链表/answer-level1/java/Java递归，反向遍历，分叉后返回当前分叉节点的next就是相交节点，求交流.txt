```
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        //定义两个指针
        ListNode pa = headA;
        ListNode pb = headB;
        //每个链表的尾节点的next,也就是要传入reverseNode(ListNode head, ListNode last)方法中的last,初始化为null;
        ListNode paEnd = null;
        ListNode pbEnd = null;
        while(paEnd == pbEnd) {
            paEnd = reverseNode(pa, paEnd);
            pbEnd = reverseNode(pb, pbEnd);
        }
        返回反向遍历分叉节点的next，即是相交节点
        return pae.next;
    }

    //反向遍历链表，每次返回last的上一节点
    public ListNode reverseNode(ListNode head, ListNode last) {
        if(head == last) {
            ListNode r = new ListNode(-1);
            r.next = last;
            return r;
        }
        if(head.next == last) {
            return head;
        }
        return reverseNode(head.next, last);
    }
}
```
可能不是效率最高的方法，只是一种尝试，欢迎大家提出意见及改进
