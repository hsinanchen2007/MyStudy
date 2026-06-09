### 解题思路
先求出链表的长度，根据长度和参数n定位到要删除的元素位置

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int GetLens(struct ListNode* head)
{
    int lens = 0;
    int i;
    struct ListNode * p = head;

    while(NULL != p)
    {
        lens += 1;
        p=p->next;
    }
    return lens;
}


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{   
    int lens = GetLens(head);
    int pos_remove =lens -n;
    int i;
    struct ListNode * pHead = ( struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * p = pHead;
    struct ListNode * q = NULL;

    if(0 == n)
        return head;
    if(NULL == head)
        return NULL;
    else
       pHead->next = head;

    for(i=0;i<pos_remove;i++)
    {
        p = p->next;
    }
    
    q = p->next;

    if(NULL != q->next)
    {
        p->next = q->next;
        free(q);

    } 
    else
        p->next = NULL;

    return  pHead->next;

}
```