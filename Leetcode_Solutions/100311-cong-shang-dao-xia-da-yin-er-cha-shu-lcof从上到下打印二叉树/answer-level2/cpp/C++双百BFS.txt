### 解题思路
用队queque解决。

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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> a;
        if(root==nullptr) return a;
        queue<TreeNode*> que;
        que.push(root);
        while(que.size()!=0)
        {
            TreeNode* c=que.front();
            a.push_back(c->val);
            que.pop();
            if(c->left!=nullptr) que.push(c->left);
            if(c->right!=nullptr) que.push(c->right);
            //TreeNode* c=que.front();
            //a.push_back(c->val);
            //que.pop();
        }
        return a;

    }
};

```