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

struct ListNode* list1;
struct ListNode* list2;
struct ListNode* list1end;

void func(struct ListNode* head, int x) {
    if (head == NULL) return;
    func(head->next, x);

    if (head->val < x) {
        if (list1 == NULL) list1end = head;
        head->next = list1;
        list1 = head;
    } else {
        head->next = list2;
        list2 = head;
    }
}

struct ListNode* partition(struct ListNode* head, int x){
    list1end = list1 = list2 = NULL;

    func(head, x);
    struct ListNode* result;

    if (list1 != NULL) {
        list1end->next = list2;
        result = list1;
    } else {
        result = list2;
    }
    return result;
}
```