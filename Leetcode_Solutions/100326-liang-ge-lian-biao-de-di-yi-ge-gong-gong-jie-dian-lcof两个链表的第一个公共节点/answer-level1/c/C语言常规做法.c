利用双指针即可解决，思路较为清晰，不再赘述。
```c
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p_1=headA,*p_2=headB;
    while(p_1!=0&&p_2!=0){
        p_1=p_1->next;
        p_2=p_2->next;
    }
    if(p_1==0){
        p_1=headA;
        headA=headB;
        headB=p_1;
        p_1=p_2;
    }
    while(p_1!=0){
        headA=headA->next;
        p_1=p_1->next;
    }
    while(headA!=0){
        if(headA==headB) return headA;
        headA=headA->next;
        headB=headB->next;
    }
    return 0;
}
```