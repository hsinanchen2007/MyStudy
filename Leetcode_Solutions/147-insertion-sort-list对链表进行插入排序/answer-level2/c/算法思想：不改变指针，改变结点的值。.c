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


struct ListNode* insertionSortList(struct ListNode* head){
    if(head==NULL){
        return NULL;
    }
    struct ListNode*p,*q;
    int temp;

    for(p=head;p;p=p->next){
        for(q=p->next;q;q=q->next){
            if(p->val > q->val){
                temp = p->val;
                p->val = q->val;
                q->val = temp;
            }
        }
    }
    return head;
}
```