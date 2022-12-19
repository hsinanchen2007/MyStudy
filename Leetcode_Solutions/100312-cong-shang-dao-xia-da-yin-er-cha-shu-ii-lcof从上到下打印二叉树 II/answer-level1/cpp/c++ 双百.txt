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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> v;
        queue<TreeNode*> que;
        if(!root)return res;
        que.push(root);
        TreeNode *p,*last=root;
        while(!que.empty())
        {
            p=que.front();
            que.pop();
            v.push_back(p->val);
            if(p->left)
                que.push(p->left);
            if(p->right)
                que.push(p->right);
            if(p==last)
            {
                res.push_back(v);
                v.clear();
                last=que.back();
            }
            }
            return res;
    }
};
```