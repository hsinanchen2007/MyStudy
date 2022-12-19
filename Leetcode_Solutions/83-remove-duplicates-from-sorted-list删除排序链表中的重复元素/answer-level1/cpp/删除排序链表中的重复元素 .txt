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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }    
        ListNode* node = head;
        ListNode* next = head->next;
        while(next != NULL) {
            if (node->val == next->val) {
                node->next = next->next;
                //delete next;
                next = next->next;
            } else {
                node = next;
                next = next->next;
            }
        }
        return head;
    }
};
```