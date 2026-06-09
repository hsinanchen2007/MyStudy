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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    struct ListNode *p, *q;
    struct ListNode *rhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    rhead->next = head;
    p = q= rhead;
    int i;
    for(i=0; i<n+1; i++){
        q = q->next;
    }
    while(q != NULL){
        q=q->next;
        p=p->next;
    }
    p->next = p->next->next;
    return rhead->next;
}
```