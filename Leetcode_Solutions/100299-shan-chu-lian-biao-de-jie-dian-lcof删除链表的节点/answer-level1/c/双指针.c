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
    struct ListNode*p=head;
    struct ListNode*q=head->next;
    if(head->val==val)
    return head->next;
    while(q!=NULL&&q->val!=val){
        p=q;
        q=q->next;
    }
    p->next=q->next;
    return head;


}


```