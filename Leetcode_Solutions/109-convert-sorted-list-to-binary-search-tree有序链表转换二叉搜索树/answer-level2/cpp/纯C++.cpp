### 解题思路
纯C++

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
    TreeNode* sortedListToBST(ListNode* head) {
        if (nullptr == head) return NULL;
        return helper(head, NULL);
    }

private:
    TreeNode* helper(ListNode* head, ListNode* tail)
    {
        ListNode* fast = head;
        ListNode* slow = head;

        if (head == tail)
        {
            return NULL;
        }

        while (fast != tail && fast->next != tail)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        TreeNode* node = new TreeNode(slow->val);
        node->left = helper(head, slow);
        node->right = helper(slow->next, tail);

        return node;
    }
};
```