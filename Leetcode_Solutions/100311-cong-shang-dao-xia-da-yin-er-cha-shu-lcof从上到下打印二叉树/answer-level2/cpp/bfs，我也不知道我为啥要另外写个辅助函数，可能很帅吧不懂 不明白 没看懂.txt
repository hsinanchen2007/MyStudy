### 解题思路
BFS的思路

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
    vector<int> res;
    queue<TreeNode*> myqueue;   
    void helper(TreeNode* pRoot)
    {
        if(pRoot==nullptr)return;
        myqueue.push(pRoot);

        while(!myqueue.empty())
        {
            TreeNode* node = myqueue.front();
            myqueue.pop();
            res.push_back(node->val);
            if(node->left)myqueue.push(node->left);
            if(node->right)myqueue.push(node->right);
        }
    }
    vector<int> levelOrder(TreeNode* root) {
        if(root==nullptr)return res;
        helper(root);
        return res;
    }
};

```