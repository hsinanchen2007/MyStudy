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
void deleteNode(struct ListNode* node) {
    struct ListNode* p=node;
    while(p->next!=NULL){
        p->val=p->next->val;
        if(p->next->next==NULL) {p->val=p->next->val;p->next=NULL;break;}
        p=p->next;
    }
}
```