### 解题思路
此处撰写解题思路
1、如果是闭环，那么快跑一定在某个时刻能赶上慢跑

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
    if((head == NULL) || (head->next == NULL))
    {
        return false;
    }
    
    struct ListNode *fast_node, *slow_node;

    fast_node = head->next->next;
    slow_node = head->next;

    while((fast_node != NULL) && (fast_node->next != NULL))
    {
        if(fast_node == slow_node)
        {
            return true;
        }

        fast_node = fast_node->next->next;
        slow_node = slow_node->next;
    }

    return false;
}
```