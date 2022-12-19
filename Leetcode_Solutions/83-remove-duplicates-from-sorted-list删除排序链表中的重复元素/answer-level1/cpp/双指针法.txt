### 解题思路
没啥好说的，快慢指针

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
        if (NULL == head)
            return head;
        ListNode* left = head;
        ListNode* right = head->next;
        ListNode* temp_start = head;
        while (left != NULL) {
            if(NULL==right) {
                left->next = NULL;
                break;
            }
            if (left->val != right->val) {
                left->next = right;            
                left = right;
            }
            right = right->next;
        }

        return head;
    }
};
```