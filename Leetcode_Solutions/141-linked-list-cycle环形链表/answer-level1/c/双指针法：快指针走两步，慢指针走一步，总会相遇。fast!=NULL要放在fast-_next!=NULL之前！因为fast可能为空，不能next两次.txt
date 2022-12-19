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
bool hasCycle(struct ListNode *head) 
{
    struct ListNode *fast,*slow;
    fast=slow=head;
    if(head==NULL)
        return false;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow)
            return true;
    }
    
    return false;

    
}
```