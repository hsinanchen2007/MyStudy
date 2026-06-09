快慢指针先求出交点，然后交点和起点相向而行，汇合处则为回环起点

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode *fast = NULL;
    struct ListNode *slow = NULL;
    struct ListNode *meet = NULL;
    struct ListNode *start = NULL;

    fast = head;
    slow = head;
    start = head;
    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;

        if(fast != NULL)
        {
            fast = fast->next;
            if(fast == slow)
            {
                meet= fast;
                break;
            }
        }
        
    }
    if(meet == NULL)
    {
        return meet;
    }
    while (start != meet)
    {
        start = start->next;
        meet = meet->next;
    }
    return meet;
    
}
```