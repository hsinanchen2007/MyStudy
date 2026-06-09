```
struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode*l, *ge, **pl = &l, **pge = &ge;
    while(head) {
        if (head->val < x) {
            *pl = head;
            pl = &head->next;
        } else {
            *pge = head;
            pge = &head->next;
        }
        head = head->next;
    }
    *pge = NULL;  //ge链表尾置空
    *pl = ge;   //l链表尾指向ge
    return l;
}
```
