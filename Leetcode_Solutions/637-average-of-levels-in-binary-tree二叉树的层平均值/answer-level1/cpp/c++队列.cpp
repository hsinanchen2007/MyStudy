```
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(!root)   return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            double ans = 0, tmp = 0;
            for(int i = 0; i < len; i++){
                TreeNode *t = q.front();
                q.pop();
                ans += t->val;
                tmp++;
                if(t->left) q.push(t->left);
                if(t->right)    q.push(t->right);
            }
            result.push_back(ans / tmp);
        }
        return result;
    }
};
```
