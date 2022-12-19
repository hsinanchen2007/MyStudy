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


struct ListNode* deleteDuplicates(struct ListNode* head){
    if (!head || !head->next)
        return head;
    
    struct ListNode* pre = head, *cur = head->next;
    while (cur && cur->val == pre->val) {
        pre = pre->next;
        cur = cur->next;
    }
    if (!cur)
        return NULL;
    if (head != pre)
        return deleteDuplicates(cur);
    
    head->next = deleteDuplicates(head->next);
    return head;
}


```