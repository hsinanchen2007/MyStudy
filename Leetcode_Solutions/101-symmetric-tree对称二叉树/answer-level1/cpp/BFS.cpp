### 解题思路


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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int k = q.size();
            vector<int> v;
            for(int i = 0 ; i < k ; ++i)
            {
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->val == INT_MAX)
                    continue;
                if(node->left)
                    q.push(node->left);
                else
                    q.push(new TreeNode(INT_MAX));
                if(node->right)
                    q.push(node->right);
                else
                    q.push(new TreeNode(INT_MAX));
            }
            vector<int> vv = v;
            reverse(v.begin(), v.end());
            if(v != vv)
                return false;
        }
        return true;
    }
};
```