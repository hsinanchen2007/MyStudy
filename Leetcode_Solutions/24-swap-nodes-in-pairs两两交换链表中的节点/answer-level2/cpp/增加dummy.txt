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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* phead = dummy;
        while (phead && phead->next) {
             auto temp2 = phead->next->next;
             auto temp1 = phead->next;
             temp2 ? temp1->next = temp2->next : temp1->next = NULL;
             temp2 ? temp2->next = temp1 : temp2 = temp1;
             phead->next = temp2;
             phead = phead->next->next;
        }
        return dummy->next;
    }
};
```