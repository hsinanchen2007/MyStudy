### 解题思路
C语言实现

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
    int sum = 0;
    struct ListNode* p = head;
    for(; p->next != NULL; p=p->next)
    {
        sum = sum * 2 + p->val;
    }
    return sum * 2 + p->val;
}
```