```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x)
{
    if( !head || !head->next )
        return head;
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->next = NULL;
    struct ListNode *cur = temp;
    struct ListNode *pnode = (struct ListNode *)malloc(sizeof(struct ListNode));
    pnode->next = head;
    head = pnode;                  // 设虚拟头节点便于比较第一位数
    struct ListNode *pre = head;
    
    while( pre->next )
    {
        if( pre->next->val >= x )       // 将当前节点的下一节点进行比较
        {
            cur->next = pre->next;
            cur = cur->next;
            pre->next = pre->next->next;        // 若当前节点的下一节点较 x 大 则将其从原链表中移除 插入temp链表中
        }
        else
            pre = pre->next;            
    }
    cur->next = pre->next;
    pre->next = temp->next;
    return head->next;
}
```

