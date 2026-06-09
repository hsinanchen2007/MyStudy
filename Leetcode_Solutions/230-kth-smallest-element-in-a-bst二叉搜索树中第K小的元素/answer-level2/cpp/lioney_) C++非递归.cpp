```
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int index = 0;
        while(root || !s.empty()) {
            while(root) {
                s.push(root);
                root = root->left;
            }
            root = s.top(); s.pop();
            if(++index == k) {
                return root->val;
            }
            root = root->right;
        }
        return -1;
    }
};
```
