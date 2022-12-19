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
struct ListNode*p=head,*q;
if(head==NULL)
return NULL;
if(head->val==val){
    head=head->next;
    free(p);
    return head;
}
p=head->next;q=head;
while(p){
    if(p->val==val){
        q->next=p->next;
        free(p);
        return head;
    }
    q=p;
    p=p->next;
}
return head;
}
```