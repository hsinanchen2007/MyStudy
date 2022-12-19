可以根据[142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)的思路将headA链表的尾部与headB链表的头部连接起来 然后借助快慢指针来解题 当然效果其实一般 算是提供一种思路吧。。
```java 
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headB==null||headA==null)
        return null;
        //获取headA链表的尾部
        ListNode tailA=headA;
        while(tailA.next!=null)
        {
            tailA=tailA.next;
        }
        //将headA链表尾部与headB头部相连
        tailA.next=headB;
        //定义快慢指针
        ListNode slow=headA,fast=headA.next;
        while(fast!=null&&fast.next!=null)
        {
            slow=slow.next;
            fast=fast.next.next;
            if(slow==fast)
            break;
        }
        //快指针抵达尾部时说明两个链表本来没有相交节点 返回null 不要忘了将两个链表解开
        if(fast==null||fast.next==null)
        {
            tailA.next=null;
            return null;
        }
        //后面就跟142题完全一样了。。。
        fast=headA;
        slow=slow.next;
        while(fast!=slow)
        {
            fast=fast.next;
            slow=slow.next;
        }
        //解开。
        tailA.next=null;
        return slow;
    }
}
```

