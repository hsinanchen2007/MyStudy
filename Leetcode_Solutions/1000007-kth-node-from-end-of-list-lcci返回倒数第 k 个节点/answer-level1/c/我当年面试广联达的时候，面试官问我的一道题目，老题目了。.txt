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


int kthToLast(struct ListNode* head, int k){
    struct ListNode* p = head;
    int i = 1;

    while(i < k) {
        p = p->next;
        i++;
    }
    struct ListNode *res = head;

    while(p->next) {
        p = p->next;
        res = res->next;
    }

    return res->val;
}
```