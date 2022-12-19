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
        ListNode* head = new ListNode(0);
        ListNode *p;
        p = head;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1 -> val < l2 -> val)
            {
                p -> next = l1;
                p = l1;
                l1 = l1 -> next;
            }
            else
            {
                p -> next = l2;
                p = l2;
                l2 = l2 -> next;
            }
        }
        if(l1 != NULL)
        {
            p -> next = l1;
        }
        if(l2 != NULL)
        {
            p -> next = l2;
        }
        return head -> next;
    }
};
```