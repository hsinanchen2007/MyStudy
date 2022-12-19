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

void swapTwo(struct ListNode* node){
    struct ListNode* p = node->next;
    struct ListNode* q = p->next;
    p->next = q->next;
    q->next = p;
    node->next  = q;
}

struct ListNode* swapPairs(struct ListNode* head){
    if(head==NULL) return NULL;
    struct ListNode* pre = head;
    struct ListNode* p = head->next;

    if(p==NULL) return head;
    head->next = p->next;
    p->next=head;
    pre = p->next;
    while(pre->next!=NULL && pre->next->next!=NULL){
        swapTwo(pre);
        pre = pre->next->next;
    }
    return p;
}
```