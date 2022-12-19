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


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
    struct ListNode* p1;
    struct ListNode* p2;
    dummy->next = head;

    p1 = dummy;
    p2 = dummy;

    while (p2 != NULL && p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    if (p2 == NULL) {
        return p1;
    }
    else {
        return p1->next;
    }
}
```