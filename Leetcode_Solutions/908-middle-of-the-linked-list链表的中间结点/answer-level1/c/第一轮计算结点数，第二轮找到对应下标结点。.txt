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

struct ListNode* middleNode(struct ListNode* head)
{    
    struct ListNode *p;
    int count=0;
    if(head==NULL)
        return NULL;
    p=head;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    p=head;
    for(int i=0;i<count/2;i++)
        p=p->next;
    return p;
}
```