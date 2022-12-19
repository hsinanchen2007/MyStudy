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


struct ListNode* deleteNode(struct ListNode* head, int val){
    if(head==NULL||head->next==NULL)
        return NULL;
    if(head->val==val)
        return head->next;
    struct ListNode*head1=(struct ListNode*)malloc(sizeof(struct ListNode));
    head1=head;
    while(head->next!=NULL)
    {
        if(head->next->val==val)
        {
            head->next=head->next->next;
            break;
        }
        head=head->next;

    }
    if(head->val==val)
    {
        head=NULL;
    }
    return head1;
}
```