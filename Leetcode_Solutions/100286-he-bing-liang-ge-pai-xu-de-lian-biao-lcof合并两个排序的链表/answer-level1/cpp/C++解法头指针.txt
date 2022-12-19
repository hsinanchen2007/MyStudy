### 解题思路
此处撰写解题思路

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *preNext = new ListNode(1);
        preNext->val = 0;
        ListNode *head = preNext;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                preNext->next = l1;
                l1 = l1->next;
            }
            else
            {
                preNext->next = l2;
                l2 = l2->next;
            }
            preNext = preNext->next;
        }

        preNext->next = (l1 == NULL) ? l2 : l1;

        return head->next;
    }
};
```