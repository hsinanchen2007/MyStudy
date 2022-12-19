### 解题思路
此处撰写解题思路
C语言递归实现，主要是判断递归的退出条件：当前节点为空，或者当前节点的next为空。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *next = NULL;

    if (!head || !head->next) {
        return head;
    }
    next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;

    return next;

}
```