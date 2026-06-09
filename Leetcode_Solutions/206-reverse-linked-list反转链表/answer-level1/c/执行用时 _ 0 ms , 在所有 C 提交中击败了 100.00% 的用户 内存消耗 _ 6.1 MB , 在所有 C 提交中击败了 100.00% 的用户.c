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
    struct ListNode*p=head;
    struct ListNode*q=head;
    struct ListNode*r=head;
    if(head==NULL){
        return head;
    }
    r=head->next;
    head->next=NULL;
    while(r){
        q=r;
        r=r->next;
        q->next=p;
        p=q;
    }
    
    return q;


}
```