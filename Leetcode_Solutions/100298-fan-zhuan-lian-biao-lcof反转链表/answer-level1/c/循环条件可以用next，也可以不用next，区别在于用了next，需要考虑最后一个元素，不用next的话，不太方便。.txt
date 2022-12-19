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


struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *tmp = NULL;
    struct ListNode *p = head;
    
    while (head->next) {
        p = head->next;
        head->next = tmp;
        tmp = head;
        head = p;
    }
    head->next = tmp;

    return head;
}
```