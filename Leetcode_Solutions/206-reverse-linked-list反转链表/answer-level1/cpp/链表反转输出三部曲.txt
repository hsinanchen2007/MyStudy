### 解题思路
1. 备份head->next
2. 修改head->next
3. 移动head和newhead
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
    ListNode* reverseList(ListNode* head) {
        ListNode *newhead = NULL;
        while(head)
        {
            ListNode *next = head->next; //备份head->next
            head->next = newhead;//修改head->next
            newhead = head;//移动head和newhead
            head = next;
        }
        return newhead;
    }
};
```