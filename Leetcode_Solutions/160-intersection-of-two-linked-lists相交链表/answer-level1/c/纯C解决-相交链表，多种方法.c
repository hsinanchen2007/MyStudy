### 解题思路
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 int getLength(struct ListNode* head)
 {
     struct ListNode *p=head;
     int length=0;
     while(p)
     {
         p=p->next;
         length++;
     }
     return length;
 }
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lengthA=getLength(headA);
    int lengthB=getLength(headB);
    int dif=lengthA-lengthB;
    if(lengthA<lengthB)//A永远指向最长的
    {
        dif=lengthB-lengthA;
        struct ListNode *p=headA;
        headA=headB;
        headB=p;
    }
    while(dif)
    {
        headA=headA->next;
        dif--;
    }
    while(headA!=headB)
    {
        headA=headA->next;
        headB=headB->next;
    }
    return headA;
}
```
```c
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(!headA||!headB)
    return NULL;
    struct ListNode *p1=headA,*p2=headB;
    while(p1!=p2)
    {
        p1=p1==NULL?headB:p1->next;
        p2=p2==NULL?headA:p2->next;
    }   
    return p1;
}
```
