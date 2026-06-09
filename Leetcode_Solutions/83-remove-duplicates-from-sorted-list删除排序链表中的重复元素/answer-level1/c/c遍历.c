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


struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(head==NULL)
       return head;
    struct ListNode *p1,*l,*p2;
    p1=head;
    l=head->next;
    while(l!=NULL)
    {
        if(p1->val==l->val)
        {
            p2=l;
            l=l->next;
            p1->next=l;
            free(p2);//释放掉被跳过的指针
        }
        else
        {
            p1=p1->next;
            l=l->next;
        }
    }
    return head;
}
```