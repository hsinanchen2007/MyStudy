```
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return helper(1, n);
    }
    vector<TreeNode*> helper(int start, int end) {
        if(start > end) return {nullptr};
        vector<TreeNode*> res;
        for(int i=start; i<=end; i++) {
            auto left = helper(start, i-1), right = helper(i+1, end);
            for(auto a:left) {
                for(auto b:right) {
                    TreeNode* node = new TreeNode(i);
                    node->left = a;
                    node->right = b;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};
```
