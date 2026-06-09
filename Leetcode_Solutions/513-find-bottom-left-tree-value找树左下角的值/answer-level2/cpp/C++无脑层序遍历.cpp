```
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            int s = q.size();
            for(int size = q.size(); size > 0; size--){
                TreeNode *newnode = q.front(); q.pop();
                if(size == s)
                    res = newnode->val;
                if(newnode->left)
                    q.push(newnode->left);
                if(newnode->right)
                    q.push(newnode->right);
            }
        }
        return res;
    }
};
```
