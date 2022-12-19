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
    if(head==NULL||head->next==NULL)
    {
        //printf("%d\n",head->val);
        return head;
    }
    else
    {
        struct ListNode *p=reverseList(head->next);
        //printf("%d\n",head->val);
        struct ListNode *q=p;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=head;
        head->next=NULL;
        return p;
    }
}
```