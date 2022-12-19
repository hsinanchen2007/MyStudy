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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector <vector<int> > res;
        if (root == NULL)
            return res;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        while (!q1.empty() || !q2.empty()){
            vector<int>level;
            while (!q1.empty()){
                TreeNode* tmp = q1.front();
                q1.pop();
                level.push_back(tmp->val);
                if (tmp->left){
                    q2.push(tmp->left);
                }
                if (tmp->right){
                    q2.push(tmp->right);
                }
            }

            while(!q2.empty()){
                TreeNode* tmp = q2.front();
                q2.pop();
                q1.push(tmp);
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```