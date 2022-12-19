### 解题思路
此处撰写解题思路

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
    queue<TreeNode*> q;
    vector<int> levelOrder(TreeNode* root) {
        if(root==NULL)return res;
        TreeNode *pre=root;
        q.push(pre);
        while(q.size()){
            pre=q.front();
            q.pop();
            res.push_back(pre->val);
            if(pre->left!=NULL)q.push(pre->left);
            if(pre->right!=NULL)q.push(pre->right);
        }
        return res;
    }
};
```