### 解题思路
第三次做此题

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
    if(head==0)
        return 0;
    struct ListNode* newHead=(struct ListNode*)malloc(sizeof(struct ListNode));
    newHead->next=0;
    struct ListNode* iter=head->next;
    while(head!=0)
    {
        head->next=newHead->next;
        newHead->next=head;
        head=iter;
        if(iter!=0)
            iter=iter->next;
    }
    head=newHead->next;
    free(newHead);
    return head;
}
```