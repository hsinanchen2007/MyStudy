如果两个链表的长度不一样，那么就让长的链表逐个向下读取直到总长度减去读取的长度等于另一个链表的长度。
这样做的原因是，一旦某个节点相同了，那么后续节点也必须相同。所以如果长的链表和短的链表有共同点的话，那么一定不在前面而会在与短的链表长度相等的那一块里。
所以可以放心大胆的将长链表的前面长的部分去掉。
所以一旦长度相等了，获取相同节点就非常简单了。
import java.util.HashSet;
import java.util.Set;
public class Solution {
    public ListNode getIntersectionNode(ListNode pHead1, ListNode pHead2) {
       /* Set<ListNode> set = new HashSet<>();
        while(headA!=null){
            set.add(headA);
            headA = headA.next;
        }
        while(headB!=null){
            if (set.contains(headB))
                return headB;
            else set.add(headB);
            headB = headB.next;
        }
        return null;*/
        if(pHead1 == null || pHead2 == null)
            return null;
        ListNode p1 = pHead1;
        ListNode p2 = pHead2;
        int p1len = getlength(p1);
        int p2len = getlength(p2);
        //如果长度不等，那么就先去掉长度差。
        if(p1len<p2len){
            int len = p2len-p1len;
            while(pHead2!=null&&len>0){
                len--;
                pHead2 = pHead2.next;
            }
            //开始对比
            while(pHead2!=null){
                if(pHead1 == pHead2)
                    return pHead1;
                pHead1 = pHead1.next;
                pHead2 = pHead2.next;
            }
        }else if(p1len>p2len){
            int len = p1len-p2len;
            while(pHead1!=null&&len>0){
                len--;
                pHead1 = pHead1.next;
            }
            while(pHead2!=null){
                if(pHead1 == pHead2)
                    return pHead1;
                pHead1 = pHead1.next;
                pHead2 = pHead2.next;
            }
        }else{
            while(pHead1!=null){
                if(pHead1 == pHead2)
                    return pHead1;
                pHead1 = pHead1.next;
                pHead2 = pHead2.next;
            }
        }
        return null;
    }
    public int getlength(ListNode pHead){
        int count = 0;
        while(pHead!=null)
        {
            count++;
            pHead = pHead.next;
        }
        return count;
    }
}