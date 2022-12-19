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


**递归**
struct ListNode* reverse3(struct ListNode* h1,struct ListNode* h2,struct ListNode* h3)
{
    h2->next=h1;
    if(h3==NULL)
      return h2;
    else
      return reverse3(h2,h3,h3->next);
}

struct ListNode* reverseList(struct ListNode* head)
{
    if(head==NULL)
      return NULL;
    return reverse3(NULL,head,head->next);
}

**迭代**
struct ListNode* reverseList(struct ListNode* head)
{
    if(head==NULL)
      return NULL;
    struct ListNode *h1,*h2,*h3;
    h1=NULL;
    h2=head;
    h3=head->next;
    while(h2!=NULL)
    {
        h2->next=h1;
        h1=h2;
        h2=h3;
        h3=h2->next;
    }
    return h2;
}