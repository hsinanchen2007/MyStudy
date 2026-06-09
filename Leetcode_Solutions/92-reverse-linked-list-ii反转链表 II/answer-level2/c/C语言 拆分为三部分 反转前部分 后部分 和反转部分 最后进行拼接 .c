当 m = 1 的情况 用到虚拟头节点
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    int x = n - m;
    int i = 0;
    struct ListNode *pnode = (struct ListNode *)malloc(sizeof(struct ListNode));
    pnode->next = head;
    head = pnode;               // 虚拟头节点 便于进行从第一个节点开始反转的情况
    struct ListNode *cur = head;
    struct ListNode *pre = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *s, *q ,*target;
    pre->next = NULL;
    while( m-1 > i )
    {
        cur = cur->next;        // 找到开始反转的上一个节点
        i++;
    }
    i = 0;
    s = cur;                    // s为开始反转的第一个节点
    cur = cur->next;
    while( x + 1 > i )          // 将其中的链表用头插法插入pre链表中
    {
        q = (struct ListNode *)malloc(sizeof(struct ListNode));
        q->val = cur->val;
        q->next = pre;
        pre = q;
        if( i == 0 )
            target = pre;       // target为开始反转的第一个节点即新链表pre的尾节点
        cur = cur->next;
        i++;
    }
    s->next = pre;
    target->next = cur;
    
    return head->next;
}
```
