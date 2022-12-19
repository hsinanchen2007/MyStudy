### 解题思路
此处撰写解题思路
使用循环和中间变量来反转链表
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
    struct ListNode* left  = NULL;
    struct ListNode* temp  = NULL;
    int i = 0;
    if(head == NULL) {
        return NULL;
    }
    while(head) {
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(i == 0) {
            temp->next = NULL;
            left = temp;
        }
        else
        {
            temp->next = left;
            left = temp;
        }
        i++;
        left->val = head->val;
        head = head->next;
    }
    return left;
}
```