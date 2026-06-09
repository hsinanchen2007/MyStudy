``` 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int x, y, num, flag=0;
    struct ListNode *p = l1, *q = l2;
    struct ListNode *cur = (struct ListNode*)malloc(sizeof(struct ListNode));
    cur->next = NULL;
    struct ListNode *ret = cur;
    while(p!=NULL || q!=NULL)
    {
        x = (p!=NULL)?p->val:0;
        y = (q!=NULL)?q->val:0;
        num = x+y+flag;
        flag = num/10;
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur = cur->next;
        cur->val = num%10;
        cur->next = NULL;
        if(p!=NULL)
            p = p->next;
        if(q!=NULL)
            q = q->next;
    }
    if(flag > 0)
    {
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur = cur->next;
        cur->val = 1;
        cur->next = NULL;
    }
    return ret->next;
}
