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
        if(head == NULL || head->next == NULL) {
            return head;
        }    
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while(cur->next != NULL) {
            if (cur->val == cur->next->val) {
                int m_iDelVal = cur->val;
                ListNode* node = cur;
                while(node != NULL) {
                    if (node->val == m_iDelVal) {
                        ListNode* next = node->next;
                        node = next;
                    } else {
                        break;
                    }
                }
                pre->next = node;
                cur = node;
            } else {
                pre = cur;
                cur = cur->next;
            }
            if(cur == NULL) {
                break;
            }
        }
        return dummy->next;
    }
};
```