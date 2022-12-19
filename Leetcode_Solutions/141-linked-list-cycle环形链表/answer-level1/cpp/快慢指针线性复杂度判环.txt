### 解题思路
人类的智慧太伟大了

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode* fast, *slow;
        slow = head->next;
        if(slow == NULL)
            return false;
        fast = head->next->next;
        while(fast != slow)
        {
            if(fast == NULL || slow == NULL)
                return false;
            if(fast->next != NULL)
                fast = fast->next->next;
            else
                return false;
            if(slow->next != NULL)
                 slow = slow->next;
            else
                return false;
        }
        return true;
    }
};
```