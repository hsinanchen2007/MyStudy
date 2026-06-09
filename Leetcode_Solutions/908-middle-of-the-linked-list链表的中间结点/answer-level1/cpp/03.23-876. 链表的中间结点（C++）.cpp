### 解题思路
打卡断了2两天，心疼

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
    ListNode* middleNode(ListNode* head) {
        ListNode *left = head;
        ListNode *right = head;
        while(right != nullptr && right->next !=nullptr) {
            left = left->next;
            right = right->next->next;      
        }
        return left;
    }
};
```