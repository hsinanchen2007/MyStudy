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


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p,*q;
    if (!head)
        return head;
    p=head;
    q=head->next;
    while(q){
        if(p->val == q->val){
            p->next =q->next;
            q = p->next;
        }
        else{
            p = q;
            q = q->next;
        }
    }
    return head;

}
```