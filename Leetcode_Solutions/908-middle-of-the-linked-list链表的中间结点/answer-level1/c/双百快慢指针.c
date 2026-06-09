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

typedef struct ListNode ListNode;
ListNode* middleNode(ListNode* head){
    ListNode*p=head,*q=head;
    while(p!=NULL){
        p=p->next;
        if(p==NULL){
            break;
        }
        p=p->next;
        q=q->next;
    }
    return q;
}
```