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


struct ListNode* removeDuplicateNodes(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *p = head->next;
    struct ListNode *q = head;
    struct ListNode *last = head;

    while(p) {
        q = head;
        while(q && q != p) {
            if (q->val == p->val) {
                last->next = p->next;
                p = last;
            }
            q = q->next;
        }
        last = p;
        p = p->next;
    }

    return head;
}
```