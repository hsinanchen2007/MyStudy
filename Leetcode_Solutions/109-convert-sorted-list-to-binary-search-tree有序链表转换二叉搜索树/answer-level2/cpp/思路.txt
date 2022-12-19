### 解题思路
比较简单，主要还是快慢指针

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
      if(!head) return NULL;
      if(!head->next) return new TreeNode(head->val);

      ListNode* fast = head;
      ListNode* slow = head;
      ListNode* pre = NULL;

      while(fast && fast->next){
        fast = fast->next->next;
        pre = slow;
        slow = slow->next;
      }
      pre->next = NULL;

      TreeNode* tree = new TreeNode(slow->val);
      tree->left = sortedListToBST(head);
      tree->right = sortedListToBST(slow->next);

      return tree;
    }
};
```