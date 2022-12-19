
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode *l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->next = NULL;
    struct ListNode *p = l1,*q = l2,*k = l3;
    int c = 0,sum = 0;

    while(p||q||c!=0){
        struct ListNode *s = (struct ListNode*)malloc(sizeof(struct ListNode));

        sum = (p?p->val:0)+(q?q->val:0)+c;
        if(sum>9){
            sum = sum%10;
            c = 1;
        }else c = 0;

        s->next = NULL;
        s->val = sum;
        k->next = s;
        k = s;
        if(p) p = p->next;
        if(q) q = q->next;
    }

    return l3->next;
}