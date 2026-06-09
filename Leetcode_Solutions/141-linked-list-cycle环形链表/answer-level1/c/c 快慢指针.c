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
bool hasCycle(struct ListNode *head) {
    //快慢指针
    if(head == NULL || head->next == NULL)
        return false;
    struct ListNode* fast = head->next;
    struct ListNode* slow = head;
    while(fast != NULL && fast->next != NULL )
    {
        if(fast == slow)
            return true;
        slow = slow->next;
        fast = ((fast->next)->next);
    }
    return false;
}
```