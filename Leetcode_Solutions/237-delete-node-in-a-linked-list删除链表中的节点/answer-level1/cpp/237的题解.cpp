```
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
    void deleteNode(ListNode* node) {
            ListNode* old_node_next = node->next;
            node->val = old_node_next->val;
            node->next = old_node_next->next;
            delete old_node_next;
            
    }
};
```
