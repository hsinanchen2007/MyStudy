```
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int index = 0;
        while(root || !s.empty()) {
            while(root) {
                s.push(root);
                root = root->right;
            }
            root = s.top(); s.pop();
            if(++index == k) return root->val;
            root = root->left;
        }
        return -1;
    }

};
```
