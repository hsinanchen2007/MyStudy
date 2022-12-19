struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int result = 0, c = 0;
    struct ListNode* l3, * p, * q;
    l3 = NULL;
    q = NULL;
    while (l1 != NULL && l2 != NULL) {
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (c == 1) {
            result = l1->val + l2->val + 1;
            c = 0;
        }
        else if (c == 0) {
            result = l1->val + l2->val;
        }
        if (result >= 10) {
            c = 1;
            p->val = result - 10;
            p->next = NULL;
        }
        else if (result < 10) {
            p->val = result;
            p->next = NULL;
        }
        if (l3 == NULL) {
            l3 = p;
            q = l3;
        }
        else {
            q->next = p;
            q = p;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 != NULL) {
        q->next = l1;
    }
    else if (l2 != NULL) {
        q->next = l2;
    }
    if(c==1 && l1==NULL &&l2==NULL){
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val=1;
        p->next=NULL;
        c=0;
        q->next=p;
        q=p;
    }
    p=p->next;
   
    while(c==1 && p!=NULL){
        
        if((p->val+1)<10){
            p->val+=1;
            c=0;
        }
        else if((p->val+1)>=10){
            p->val=p->val+1-10;
            c=1;
        }
        p=p->next;
        q=q->next;
    }
    if(c==1 && p==NULL){
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val=1;
        p->next=NULL;
        c=0;
        q->next=p;
        q=p;
    }
    return l3;
}