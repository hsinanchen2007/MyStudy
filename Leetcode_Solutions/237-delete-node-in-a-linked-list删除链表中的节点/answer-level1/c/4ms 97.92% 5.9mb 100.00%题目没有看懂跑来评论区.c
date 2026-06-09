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
void deleteNode(struct ListNode* node) {
    if(node==NULL){
        return ;
    }
    while(node->next!=NULL){
        node->val=node->next->val;
        if(node->next->next==NULL){
            break;
        }
        node=node->next;
    }
    node->next=NULL;
}
```