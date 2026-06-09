复杂度跟官方解答一样，但是官方解答怎么确定哪一个是相交结点呢？

1 初始化两指针分别指向A，B头结点，遍历链表，获得长度lenA,lenB.
2，指针指回头结点，让长的链表先走|lenA-lenB|，如果相交，两指针必然指向同一个结点，此时返回结点。
否则返回null
class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int lenA=0;
        int lenB=0;
        ListNode tmpA=headA;
        ListNode tmpB=headB;
        while(tmpA!=null){
            lenA++;
            tmpA=tmpA.next;
        }
        while(tmpB!=null){
            lenB++;
            tmpB=tmpB.next;
        }
        tmpA=headA;
        tmpB=headB;
        while(lenB<lenA){
            tmpA=tmpA.next;
            lenA--;
        }
         while(lenB>lenA){
            tmpB=tmpB.next;
           lenB--;
        }
        for(int i=0;i<lenB;i++){
            if(tmpA==tmpB) return tmpB;
            tmpB=tmpB.next;
            tmpA=tmpA.next;
        }
        return null; 
    }
}