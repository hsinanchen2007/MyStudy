思路：指定两个指针p,q,让q先走n步，再让p,q同时行走直到q为null,p指向待删除的前一个结点。
再将待删除结点删除。
同时为了考虑[1]的情况，设置一个if判断条件，如果倒数第n个结点为第一个结点，则直接删除。

源代码：struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* p = head;
    struct ListNode* q = head;
    int i;
    for(i=1;i<=n;i++){
        q = q->next;
    }
    
    if(!q){
        head = p->next;
        free(p);
        return head;
    }

    while(q){
        q = q->next;
        if(q) p = p->next;
    }

    q = p->next;
    p->next = q->next;
    free(q);
    return head;   
}