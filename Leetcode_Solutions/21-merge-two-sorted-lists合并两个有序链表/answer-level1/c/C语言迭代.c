

```
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    //创建一个节点,用来合并链表，返回头结点时使用
    struct ListNode* h = (struct ListNode * ) malloc(sizeof(struct ListNode));
    if(h == NULL)
    {
        return NULL;
    }
    memset(h, 0, sizeof(struct ListNode));
    
    struct ListNode* pre = h;

    //这个部分，官方有题解。建议没想到的看下思路，然后自己实现代码，遇到不懂再去参考别代码。
    while(!l1 && !l2 )
    {
        if (l1->val <= l2->val)
        {
            pre->next = l1;
            l1 = l1->next;
        }
        else
        {
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    
    //因为h节点是临时的节点，为了防止内存泄露，需要free。
    pre->next = (l1 == NULL ? l2 : l1);
    pre = h->next;
    free(h);

    return pre;
}
```
