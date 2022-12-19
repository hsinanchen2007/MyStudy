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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *p1, *p2, *p3;
    p1 = head;
    p2 = head;
    p3 = head;
    for (int i = 0; i < n; i++) {
        p1 = p1->next;
    }
    if (p1 == NULL) {
        head = head->next;
        free(p2);
        return head;
    }
    p1 = p1->next;
    p2 = p2->next;
    while (p1 != NULL) {
        p1 = p1->next;
        p2 = p2->next;
        p3 = p3->next;
    }
    p3->next = p2->next;
    free(p2);
    return head;
}
```