### 解题思路
把后一个节点的值搬到前一个节点的值

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
    while(node->next->next!=NULL){
        node->val=node->next->val;
        node=node->next;
    }
    node->val=node->next->val;
    free(node->next);
    node->next=NULL;
}
```