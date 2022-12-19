### 解题思路
基本思想还是双指针遍历整个链表，左指针保存前置结点，右指针判断是否删除该节点。为了解决删除结点为链表第一个结点这个问题，又新建了一个头结点。这样就不用在分类讨论了，z可以保证代码的简洁。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* phead;
    struct ListNode* pre;
    struct ListNode* tail;
    phead=(struct ListNode*)malloc(sizeof(struct ListNode));
    phead->val=0;
    phead->next=head;
    pre=phead;
    tail=pre->next;
    while(tail)
    {
        if(tail->val==val)
        {
            tail=tail->next;
            pre->next=tail;
        }
        else 
        {
            pre=tail;
            tail=tail->next;
        }
    }
    return phead->next;
}
```