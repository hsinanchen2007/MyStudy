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


bool isPalindrome(struct ListNode* head){
    struct ListNode* p=head;
    int num;
    for(num=0;p;p=p->next,num++);
    p=head;
    for(int mid=1;mid<=num/2;mid++,p=p->next);
    struct ListNode*copy=(struct ListNode*)malloc(sizeof(struct ListNode));
    copy->next=NULL;
    struct ListNode* t=NULL;
    while(p)
    {
        t=p->next;
        p->next=copy->next;
        copy->next=p;
        p=t;
    }
    copy=copy->next;
while(copy)
{
    if(copy->val!=head->val) return false;
    copy=copy->next;
    head=head->next;
}
return true;
}
```