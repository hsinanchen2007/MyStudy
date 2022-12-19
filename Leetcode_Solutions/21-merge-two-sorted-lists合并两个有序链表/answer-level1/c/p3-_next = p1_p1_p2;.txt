
```c

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    struct ListNode* p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p4 = p3;
    while(p1 && p2){
        if(p1->val < p2->val){
            p3->next = p1;
            p1 = p1->next;
        }else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3=p3->next;
    }
    p3->next = p1?p1:p2;
    struct ListNode* p5 = p4->next;
    free(p4);
    return p5;

}
```