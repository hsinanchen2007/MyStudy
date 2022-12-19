### 解题思路
快慢指针找到链表中点，递归调用左右子树。

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
        if(!head) return nullptr;
        ListNode* slowp = head;
        ListNode* fastp = head;
        ListNode* preslowp = nullptr;
        while(fastp != nullptr && fastp->next != nullptr)
        {
            preslowp = slowp;
            slowp = slowp->next;
            fastp = fastp->next->next;
        } 
        if(preslowp != nullptr)
        {
            preslowp->next = nullptr;
            preslowp = head;
        }
            
        TreeNode* r = new TreeNode(slowp->val);
        r->left = sortedListToBST(preslowp);
        r->right = sortedListToBST(slowp->next);
        return r;
    }
};
```