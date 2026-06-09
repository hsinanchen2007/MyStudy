### 解题思路
while( && )
while()
while()
return

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->next=0;
    struct ListNode* rear=head;

    while(l1!=0&&l2!=0)
        if(l1->val<l2->val)
        {
            struct ListNode* node=l1;
            l1=l1->next;
            node->next=rear->next;
            rear->next=node;
            rear=rear->next;
        }
        else
        {
            struct ListNode* node=l2;
            l2=l2->next;
            node->next=rear->next;
            rear->next=node;
            rear=rear->next;
        }
    while(l1!=0)
    {
        struct ListNode* node=l1;
        l1=l1->next;
        node->next=rear->next;
        rear->next=node;
        rear=rear->next;
    }
    while(l2!=0)
    {
        struct ListNode* node=l2;
        l2=l2->next;
        node->next=rear->next;
        rear->next=node;
        rear=rear->next;
    }

    rear=head->next;
    free(head);
    return rear;
}


```