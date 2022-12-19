```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        queue<TreeNode *> q;
        if(root) q.push(root);
        while(!q.empty()) {
            int len = q.size();
            for(int i = 0; i < len; ++i) {
                TreeNode *top = q.front();
                q.pop();
                if(top->right) q.push(top->right);
                if(top->left) q.push(top->left);
            }
            ans++;
        }
        return ans;
    }
};
```
