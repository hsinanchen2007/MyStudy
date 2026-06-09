```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val)
{
    if( !head )
    {
        return NULL;
    }
    struct ListNode *p;
    p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->next = head;
    head = p;                           // 虚拟一个头节点 便于进行第一个节点的删除操作
    struct ListNode *s = head;
    struct ListNode *q = head->next;    // 用q遍历链表 s节点始终在q的前一个 便于进行删除操作
    struct ListNode *r = NULL;
    
    while( q != NULL )
    {
        if( q->val == val )
        {
            q = q->next;
            r = s->next;
            s->next = r->next;
            free(r);
        }
        else
        {
            q = q->next;
            s = s->next;
        }
    }
    return head->next;
}
```
