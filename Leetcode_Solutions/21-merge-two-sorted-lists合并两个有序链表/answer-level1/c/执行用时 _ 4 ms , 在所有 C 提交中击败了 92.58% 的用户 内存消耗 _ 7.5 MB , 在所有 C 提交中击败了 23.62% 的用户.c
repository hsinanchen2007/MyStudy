### 解题思路
指针从两个链的起始开头，较小的节点为当前节点并指针后移。当其中一条链走到末尾，设置哨兵。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *dummy = malloc(sizeof(struct ListNode)), *p = dummy;
    if (l1 == NULL && l2 == NULL) return NULL;
    while (l1 != NULL || l2 != NULL) {
        int var1 = (l1 != NULL) ? l1->val : INT_MAX;
        int var2 = (l2 != NULL) ? l2->val : INT_MAX;
        if (var1 <= var2) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    return dummy->next;
}
```