# 思路：快慢指针

1.两个没有环的链表如果是相交于某一结点，如上图所示，这个结点后面都是共有的。所以如果两个链表相交，那么两个链表的尾结点的地址也是一样的。程序实现时分别遍历两个单链表，直到尾结点。判断尾结点地址是否相等即可。时间复杂度为O(L1+L2)。
2.如何找到第一个相交结点？判断是否相交的时候，记录下两个链表的长度，算出长度差len，接着先让较长的链表遍历len个长度，然后两个链表同时遍历，判断是否相等，如果相等，就是第一个相交的结点。

```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA ==NULL || headB == NULL){
            return NULL;
        }
        ListNode *A = headA;
        ListNode *B = headB;
        int L1_length = 0;
        int L2_length = 0;
        int len = 0;
        while(A->next){
            L1_length++;
            A = A->next; 
        }
        while(B->next){
            L2_length++;
            B = B->next; 
        }
        if(A==B){
            if(L1_length>=L2_length){
                len = L1_length - L2_length;
                A = headB;
                B = headA;
            }else{
                len = L2_length - L1_length;
                A = headA;
                B = headB;
            }
            while(len){
                B = B->next;
                len--;
            }
            while(A != B){
                A = A->next;
                B = B->next;
            }
            return A;    
        }else{
            return NULL;  
        }
    }
};
```
