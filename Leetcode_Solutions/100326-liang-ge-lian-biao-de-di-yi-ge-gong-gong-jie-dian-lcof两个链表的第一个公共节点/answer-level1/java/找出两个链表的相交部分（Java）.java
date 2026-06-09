如果两个无环链表相交,那么从相交节点开始,一直到两个链表终止的这一段,是两个链表共享的。

因此解决该问题的具体过程如下:

1. 链表1从头节点开始，走到最后一个节点(不是结束)，统计链表1的长度记为len1，同时记录链表1的最后一个节点记为end1 

2. 链表2从头节点开始，走到最后一个节点(不是结束)，统计链表2的长度记为len2，同时记录链表2的最后一个节点记为end2。 

3. 如果end1!=end2，说明两个链表不相交，返回nul即可。如果end=end2，说明两个链表相交，进入步骤4来找寻第一个相交节点。 

4. 如果链表1比较长，链表1就先走len1-len2步。如果链表2比较长，链表2就先走len2-len1步。然后两个链表一起走，一起走的过程中，两个链表第一次走到一起的那个节点，就是第一个相交的节点。 

```
public class Solution { 

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) { 
        if(headB==null||headA==null) return null; 
        ListNode cur1=headA,cur2=headB; 
        int n=0; 
        while(cur1!=null){ 
            n++; 
            cur1=cur1.next; 
        }

        while(cur2!=null){ 
            n--;
            cur2=cur2.next; 
        } 
        cur1=n>0?headA:headB; 
        cur2=cur1==headA?headB:headA; 
        n=Math.abs(n); 
        while(n>0){ 
            cur1=cur1.next; 
            n--;
        } 

        while(cur1!=cur2){ 
            cur2=cur2.next; 
            cur1=cur1.next; 
        } 
        return cur1; 
    } 
} 
```