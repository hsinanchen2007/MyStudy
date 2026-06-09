递归法就不写了，大家都会
```c++ []
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode> s;
        while(root || !s.empty()) {
            while(root) {
                s.push(*root);
                ans.push_back(s.top().val);
                root = root->left;
            }
            if(!s.empty()) {
                root = s.top().right;
                s.pop();    
            }
        }
    return ans;
    }
};
```