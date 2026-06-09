```
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)   return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *node;
        while(!q.empty()){
            for(int size = q.size(); size > 0; size--){
                node = q.front();
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
                if(size == 1)
                res.push_back(node->val);
                q.pop();
            }
        }
        return res;
    }
};
```
