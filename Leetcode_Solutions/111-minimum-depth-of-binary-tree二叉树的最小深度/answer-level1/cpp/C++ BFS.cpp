```
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0; 
        while(!q.empty()){
            int len = q.size();
            depth++;
            for(int i = 0; i < len; i++){
                TreeNode* now = q.front();
                q.pop();
                if(now->left == NULL && now->right == NULL) return depth;
                if(now->left != NULL) q.push(now->left);
                if(now->right != NULL) q.push(now->right);
            }
        }
        return depth;
    }
};
```
