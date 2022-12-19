双指针法，应用场景有求链表中间节点，求倒数的节点，判断是否有环，判断环入口，判断相交点。这些的都可以看作是把一个链表的问题变成了两个链表的问题。

回到这一道题，因为两个链表的后半段是相同的，很容易想到只要求出两个链表前半段的长度差，消除长度差后双指针同步向前，便能找到相交点。
```
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;

        ListNode * nodeA = headA;
        ListNode * nodeB = headB;
        
        while(nodeA){
            lenA++;
            nodeA = nodeA->next;
        }

        while(nodeB){
            lenB++;
            nodeB = nodeB->next;
        }

        nodeA = headA;
        nodeB = headB;
        if(lenB > lenA){
            for(int i = 0; i < lenB - lenA; i++){
                nodeB = nodeB->next;
            }
        }
        else{
            for(int i = 0; i < lenA - lenB; i++){
                nodeA = nodeA->next;
            }
        }

        while(nodeA&&nodeA!=nodeB){
            nodeA=nodeA->next;
            nodeB=nodeB->next;
        }

        return nodeA;
    }
```


双指针法将原有的链表变换成LA+LB和LB+LA两个链表，这样两个链表的长度相同，不必事先求解两个链表的长度差了，直接像上一个方法一样双指针同步向前，便能找到相交点。 

```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(!headA||!headB)
            return NULL;


        ListNode * curA = headA;
        ListNode * curB = headB;

        while(curA!=curB){
            curA = curA->next;
            curB = curB->next;

            if(!curA&&!curB)
                return NULL;

            if(!curA){
                curA = headB;
            }

            if(!curB){
                curB = headA;
            }

        }

        return curA;

    }
};
```
