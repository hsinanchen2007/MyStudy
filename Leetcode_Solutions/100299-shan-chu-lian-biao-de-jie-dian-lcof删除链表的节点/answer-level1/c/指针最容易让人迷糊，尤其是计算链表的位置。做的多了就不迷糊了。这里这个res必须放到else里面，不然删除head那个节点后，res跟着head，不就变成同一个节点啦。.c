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


struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode *res = calloc(1, sizeof(struct ListNode));
    res->next = head;
    struct ListNode *bak = res;

    while (head != NULL) {
        if (head->val == val) {
            res->next = head->next;
        }
        else {
            res = res->next;
        }
        head = head->next;
    }

    return bak->next;
}
```