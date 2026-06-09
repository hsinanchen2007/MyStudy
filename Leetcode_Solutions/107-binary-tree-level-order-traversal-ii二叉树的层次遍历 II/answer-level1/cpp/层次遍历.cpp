### 解题思路
层次遍历，最后将层次间反序

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        TreeNode* p = root;
        TreeNode* last = root;
        queue<TreeNode*> que; que.push(root);
        vector<vector<int>> leall= {{root->val}};
        vector<int> le;
        while(!que.empty())
        {
            p = que.front(); que.pop();
            if(p->left)
            {
                que.push(p->left);
                le.push_back(p->left->val);
            }
            if(p->right)
            {
                que.push(p->right);
                le.push_back(p->right->val);
            }
            if(p == last && !que.empty())
            {
                last = que.back();
                leall.push_back(le);
                le.clear();
            }
        }
        reverse(leall.begin(), leall.end());
        return leall;
    }
};
```