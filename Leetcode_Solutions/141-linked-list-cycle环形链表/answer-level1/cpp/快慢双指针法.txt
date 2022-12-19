### 解题思路


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
        ListNode* pFast = head;
        ListNode* pSlow = head;
        while (pFast != NULL && pFast->next != NULL)
        {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
            if (pFast == pSlow)
            {
                return true;
            }
        }
        return false;
    }
};
```