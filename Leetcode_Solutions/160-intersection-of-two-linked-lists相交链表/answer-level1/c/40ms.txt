struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *a = headA;
    struct ListNode *b = headB;

    while(a!=NULL&&b!=NULL){
        a=a->next;
        b=b->next;
    }
    if(a==NULL) a = headB;
    else(b = headA);

    while(a!=NULL&&b!=NULL){
        a=a->next;
        b=b->next;
    }

    if(a==NULL) a = headB;
    else(b = headA);

    while(a!=NULL&&b!=NULL){
        if(a==b) return a;
        else{
            a=a->next;
            b=b->next;
        }
    }
    return NULL;
}