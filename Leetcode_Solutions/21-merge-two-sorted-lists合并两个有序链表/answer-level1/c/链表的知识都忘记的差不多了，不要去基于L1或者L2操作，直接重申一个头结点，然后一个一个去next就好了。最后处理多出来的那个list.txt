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


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *res = (struct ListNode*)malloc(sizeof(struct ListNode));
    res->next = NULL;
    struct ListNode *record = res;
    
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            res->next = l1;
            l1 = l1->next;
        }
        else {
            res->next = l2;
            l2 = l2->next;
        }
        res = res->next;
    }

    if (l1) {
        res->next = l1;
    }
    if (l2) {
        res->next = l2;
    }

    return record->next;
}
```