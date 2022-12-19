```
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int len1=0,len2=0;
    struct ListNode *p=l1,*q=l2;
    while(p){
        len1++;
        p=p->next;
    }
    while(q){
        len2++;
        q=q->next;
    }
    p=l1,q=l2;
    int res,jin=0,i,j;
    struct ListNode *ans = (struct ListNode*)malloc(sizeof(struct ListNode));
    ans->next = NULL;
    struct ListNode *pre,*pos=ans;
    for(i=0,j=0; i<len1&&j<len2; i++,j++){
        pre = pos;
        res=p->val+q->val+jin;
        jin=res/10;
        res=res%10;
        pos->val = res;
        pos->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        pos = pos->next;
        pos->next = NULL;
        p=p->next;
        q=q->next;
    }
    while(i<len1){
        pre = pos;
        res = p->val+jin;
        jin=res/10;
        res=res%10;
        pos->val = res;
        pos->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        pos = pos->next;
        pos->next = NULL;
        p=p->next;
        i++;
    }
    while(j<len2){
        pre = pos;
        res=q->val+jin;
        jin=res/10;
        res=res%10;
        pos->val = res;
        pos->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        pos = pos->next;
        pos->next = NULL;
        q=q->next;
        j++;
    }
    if(jin==1){
        pre = pos;
        pos->val = jin;
        pos->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        pos = pos->next;
        pos->next = NULL;
    }
    pre->next = NULL;
    return ans;
}
```
