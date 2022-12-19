### 解题思路

使用指针即可

### 代码

```c

struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL) return NULL;
    struct ListNode *p, *q, *r;
    r = NULL;
    p = head->next;
    q = head;
    head->next = NULL;
    while( p != NULL){
        printf("q = %d, p = %d\n", q->val, p->val);
        r = p->next;
        p->next = q;
        q = p;
        p = r;
    }
    head = q;
    return head;
}
```