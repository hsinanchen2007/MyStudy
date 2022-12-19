### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* PLNODE;

//获取链表尾节点的指针
PLNODE GetpTail(PLNODE list)
{
    if(NULL == list)
        return NULL;
    else
    {
        PLNODE p = list;
        while(p->next != NULL)
        {
            p = p->next;
        }
        return p;
    }

}
//获取链表的长度
int GetListLens(PLNODE list)
{
    int lens = 0;
     PLNODE p = list;
    while(p != NULL)
    {
        lens ++;
        p = p->next;
    }
    return lens;
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{

    int lens = GetListLens(l1) + GetListLens(l2);
    int temp;
    PLNODE pTail1 = GetpTail(l1);
   
    if(l1 == NULL)
        l1 = l2;
    else if(l2 == NULL)
        ;
    else
        pTail1->next = l2;
    PLNODE p = l1;
    PLNODE q = NULL;

    for(p = l1 ;p != NULL;p=p->next )
    {
        for(q=p->next; q != NULL; q=q->next)
        {
            if(q->val < p->val)
            {
                temp = p->val;
                p->val = q->val;
                q->val = temp;
            }

        }

    }
    return l1;
    
}
    



```