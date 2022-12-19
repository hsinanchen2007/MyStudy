### 解题思路

无

### 代码

```cpp
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        ListNode *ans = NULL;
        ListNode *head = NULL;
        while (l1 != NULL && l2 != NULL)
        {
            if (ans == NULL)
            {
                if (l1->val < l2->val)
                {
                    ans = l1;
                    head = ans;
                    l1 = l1->next;
                    head->next = NULL;
                }
                else
                {
                    ans = l2;
                    head = ans;
                    l2 = l2->next;
                    head->next = NULL;
                }
            }
            else
            {
                if (l1->val < l2->val)
                {
                    head->next = l1;
                    head = head->next;
                    l1 = l1->next;
                    head->next = NULL;
                }
                else
                {
                    head->next = l2;
                    head = head->next;
                    l2 = l2->next;
                    head->next = NULL;
                }
            }
        }

        if(l1 == NULL)
        {
            while(l2 != NULL)
            {
                head->next = l2;
                head = head->next;
                l2 = l2->next;
                head->next = NULL;
            }
        }
        if(l2 == NULL)
        {
            while(l1 != NULL)
            {
                head->next = l1;
                head = head->next;
                l1 = l1->next;
                head->next = NULL;
            }
        }
        return ans;
    }
};
```