# 给出两种方法 
> 注意：本题的List并没有哨兵结点，如果实现方法中带有哨兵结点，是不行的

## 递归方法：
```c []
struct ListNode *reverseList(struct ListNode *head)
{
    if (!head)
    {
        return NULL;
    }
    
    if (!head->next)
    {
        return head;
    }
    struct ListNode *lNew = reverseList(head->next);

    //此处注意，因为只有一个节点的时候就返回了，但是返回时，head节点是返回链的上一个节点
    head->next->next = head; //将当前节点的作为下一个节点的next节点
    head->next = NULL;       //将取下的节点断开原链，不然回形成环

    return lNew;
}
```
## 迭代方法，需注意没有哨兵结点
```c []
struct ListNode *reverseList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode *p = head;
    struct ListNode *lNew = (struct ListNode*)malloc(sizeof(struct ListNode));
    lNew=NULL;

    while (p != NULL)
    {
        //将首节点从链表上取下来
        head = p->next;
        //插入到新链
        p->next = lNew;
        lNew = p;
        //更新p
        p = head;
    }
    free(head);
    head = lNew;
    if (!p)
    {
        free(p);
    }
    p = NULL;

    return head;
}
```