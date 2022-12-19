### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int is_ok(struct ListNode *head, struct TreeNode *root)
{
    if(head==NULL)
        return 1;
    if(root==NULL)
        return 0;
    if(head->val==root->val)
        return is_ok(head->next, root->left) || is_ok(head->next,root->right);
    return 0;
}

bool isSubPath(struct ListNode* head, struct TreeNode* root){
    if(root==NULL)
        return false;
    return is_ok(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
}


```