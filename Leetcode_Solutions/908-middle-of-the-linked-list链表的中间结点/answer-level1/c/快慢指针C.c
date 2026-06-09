解题思路：快指针q走两步，慢指针p走一步
终止条件：如果链表长度是偶数q->next == NULL
         如果奇数，q->next->next == NULL
```
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* p =head,*q= head;
    while(q->next){
        if(q->next->next == NULL)
           return p->next; 
        q = q->next->next;
        p = p->next;
    }
    return p;
}
```
