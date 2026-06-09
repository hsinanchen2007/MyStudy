```c++
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
        if (!head) return head;
        auto newHead = reverseList(head->next);
        if (!newHead) return head;
        auto node = newHead;
        while (node->next) {
            node = node->next;
        }
        node->next = head;
        head->next = nullptr;
        return newHead;
    }
};
```