

```
/* 防止空指针的使用 */
struct Node* copyRandomList(struct Node* head) 
{
    if(!head)
    {
        return NULL;
    }
    
    struct Node* p = head;
    struct Node* copyhead = NULL;
    
    /* 原链表重建 */
    while(p)
    {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        
        node->val = p->val;
        node->next = p->next;
        node->random = NULL;
        p->next = node;
        p = p->next->next;
    }
    
    p = head;
    
    /* 复制random指针 */
	while(p)
    {
        if(p->random)
        {
            p->next->random = p->random->next;
        }
        p = p->next->next;
    }
    
    p = head;
    copyhead = head->next;
    
    /* 拆解分出复制链表 */
    while(p)
    {
        struct Node* q = p->next;
        
        if(p->next)
        {
            p->next = p->next->next;
            
            if(q->next)
            {
                q->next = q->next->next;
            }
        }
        
        p = p->next;
        
    }
    
    return copyhead;
}
```

