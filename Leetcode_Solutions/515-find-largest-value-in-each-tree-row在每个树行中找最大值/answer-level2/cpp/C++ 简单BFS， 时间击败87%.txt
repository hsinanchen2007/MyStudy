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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<int> res;
        if(root==NULL) {
            return res;
        }
        int level_size=1;
        int next_level_size=0;
        Q.push(root);
        while(!Q.empty()) {
            int tmp=INT_MIN;
            next_level_size=0;
            for(int i=0;i<level_size;i++) {
                TreeNode* cur=Q.front();
                if(cur->val>tmp) {
                    tmp=cur->val;
                }
                if(cur->left) {
                    Q.push(cur->left);
                    next_level_size++;
                }
                if(cur->right) {
                    Q.push(cur->right);
                    next_level_size++;
                }
                Q.pop();
            }
            level_size=next_level_size;
            res.push_back(tmp);
        }
        return res;
    }
};
```
