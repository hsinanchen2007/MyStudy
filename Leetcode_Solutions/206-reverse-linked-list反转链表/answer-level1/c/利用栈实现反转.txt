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
#define maxSize 10000


struct ListNode* reverseList(struct ListNode* head){
    int stack[maxSize];
    int tail = 0;
    struct ListNode* obj = head;
    while(obj){
        stack[tail++] = obj->val;
        obj = obj->next;
    }
    obj = head;
    while(obj){
        obj->val = stack[--tail];
        obj = obj->next;
    }
    return head;
}
```