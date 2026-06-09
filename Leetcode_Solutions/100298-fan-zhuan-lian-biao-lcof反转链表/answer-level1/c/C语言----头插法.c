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


struct ListNode* reverseList(struct ListNode* head){
struct ListNode*h=NULL;
struct ListNode*p;
while(head!=NULL)
{
    p=head;
    head=head->next;
    p->next=h;
    h=p;
}
free(head);
return h;
}
```