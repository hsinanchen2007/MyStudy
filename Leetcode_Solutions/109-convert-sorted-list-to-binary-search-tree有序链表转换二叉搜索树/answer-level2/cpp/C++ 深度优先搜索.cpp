```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(ListNode* beg, ListNode* end) {
        if (beg == end) {
            if (beg == NULL) return NULL;
            auto node = new TreeNode(beg->val);
            return node;
        }
        if (beg->next == end) {
            auto node = new TreeNode(beg->val);
            node->right = helper(beg->next, end);
            return node;
        }
        auto prev = beg;
        auto slow = beg->next;
        auto fast = beg->next->next;
        while (fast != end && fast->next != end) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        auto node = new TreeNode(slow->val);
        node->left = helper(beg, prev);
        node->right = helper(slow->next, end);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* end = head;
        while (end != NULL && end->next != NULL) end = end->next;
        return helper(head, end);
    }
};
```
![image.png](https://pic.leetcode-cn.com/9d5dd6c33a82ac18e898b6d7f07f273fdfd90a82b3eb3e346e55f5fde578ed01-image.png)

