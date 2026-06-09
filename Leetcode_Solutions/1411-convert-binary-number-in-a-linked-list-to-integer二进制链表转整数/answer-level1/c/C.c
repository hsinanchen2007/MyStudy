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


int getDecimalValue(struct ListNode* head){
    int result = 0;
    while (head) {
        result = result * 2 + head->val;
        head = head->next;
    }
    return result;
}

```