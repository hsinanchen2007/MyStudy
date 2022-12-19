### 解题思路
找链表中间点：用快慢指针while(fast!=tail&&fast->next!=tail){
            slow=slow->next;
            fast=fast->next->next;
        }
半闭半开区间，来二分法
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
    TreeNode* build(ListNode*head, ListNode* tail){
        if(head==tail) return 0;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=tail&&fast->next!=tail){
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode* node=new TreeNode(slow->val);
        node->left=build(head,slow);
        node->right=build(slow->next,tail);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head,nullptr);
    }
};
```