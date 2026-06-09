```
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur = head, *prev = NULL, *tmp = NULL;
        ListNode *new_head = head;
        while(cur != NULL)
        {
            if(cur->val == val)
            {
                tmp = cur;
                cur = cur->next;
                if(prev != NULL)
                {
                    prev->next = cur;
                }
                else
                {
                    new_head = cur;
                }
                delete tmp;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        return new_head;
    }
};
```
