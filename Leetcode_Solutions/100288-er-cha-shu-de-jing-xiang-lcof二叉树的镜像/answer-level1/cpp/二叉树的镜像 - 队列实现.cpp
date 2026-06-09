### 解题思路
用队列进行层次遍历，将根节点的右子树变成做子树

### 代码

```cpp
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
    //q1用来存题目给的树，其树根为root
    queue<TreeNode*> q1;
    //q2用来存结果的树，其树根为head
    queue<TreeNode*> q2;
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL) return root;
        TreeNode *head = new TreeNode(root->val);
        q1.push(root);
        q2.push(head);
        while(!q1.empty()){
            TreeNode *root = q1.front(); q1.pop();
            TreeNode *cur = q2.front(); q2.pop();
            if(root->right){
                q1.push(root->right);
                TreeNode *right = new TreeNode(root->right->val);
                cur->left = right;
                q2.push(right);
            }
            if(root->left){
                q1.push(root->left);
                TreeNode *left = new TreeNode(root->left->val);
                cur->right = left;
                q2.push(left);
            }
        }
        return head;
    }

};
```