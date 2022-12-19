### 解题思路


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* find(struct ListNode* node1,struct ListNode* node2){
    if(node2->next==NULL) return node1;
    if(node2->next->next==NULL) return node1->next;
    return find(node1->next,node2->next->next);
}



struct ListNode* middleNode(struct ListNode* head){
    return find(head,head);
}
```