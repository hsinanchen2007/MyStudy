下面的代码封装的代码在OJ平台无法通过，但是在Windows下的MSV编译器以及Linux平台下的GCC编译器都能通过并正确运行。让我十分疑惑，但我想了想还是贴上来吧，毕竟许多C语言解似乎内存管理有问题。

```
struct ListNode* partition(struct ListNode* head, int x){
    //空链表和只有一个节点情况，直接返回即可
    if(!head || !head->next)
        return head;
       
    //定义2个零时节点，一个处理<的节点，一个处理>=的节点。
    struct ListNode* tLess = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tMore = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!tLess || !tMore)
    {
        goto lab;   //内存分配失败，集中到lab处处理并ret函数。
    }
    memset(tLess, 0, sizeof(struct ListNode));
    memset(tMore, 0, sizeof(struct ListNode));

    struct ListNode* less = tLess;
    struct ListNode* more = tMore;
    struct ListNode* pre = head;

    while(pre)
    {
        if(pre->val < x)
        {
            less->next = pre;
            less = less->next;
        }
        else
        {
            more->next = pre;
            more = more->next;
        }
        
        pre = pre->next;
    }
    //合并2个链表
    less->next = tMore->next; 
    more->next = NULL;
    
    //回收内存
    free(tLess);
    free(tMore);
    
    //重置head指针，保证其指向新链表头结点。
    head = tLess->next;
    return head;

lab:
    if(tLess)
        free(tLess);
    if(tMore)
        free(tMore);
    return NULL;
}
```
