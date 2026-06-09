两种思路，一是两次遍历计数，二是双指针遍历一次。后者可以少一些计数的步骤。
如果题目中链表没有头结点，可以在做题时自己加一个头结点统一①空表和非空表②第一个结点和剩余结点的操作，在做完题最后返回没有头结点的链表，并free头结点。
```
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *L = (struct ListNode*)malloc(sizeof(struct ListNode));
    L->next = head;
    struct ListNode *p=L,*q=L;
    for(int i=0;i<n+1;i++){
        p = p->next;
    }
    while(p){
        p = p->next;
        q = q->next;
    }
    q->next = q->next->next;
    head = L->next;
    free(L);
    return head;
}
```
