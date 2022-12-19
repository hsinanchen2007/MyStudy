### 解题思路
按照初始代码执行用时只超过了20%多的用户
稍微改一下，牺牲一点内存，直接接近双百

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
//初始代码
//node->val=node->next->val;
//node->next=node->next->next;
        
        struct ListNode* p=node->next;
        struct ListNode* q=p->next;
        node->val=p->val;
        node->next=q;
        free(p);
}
```