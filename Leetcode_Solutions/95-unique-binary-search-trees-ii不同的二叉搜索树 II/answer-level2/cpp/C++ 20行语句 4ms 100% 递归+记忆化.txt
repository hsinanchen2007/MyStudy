```
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode *>>> memo(n+1, vector<vector<TreeNode *>>(n+1));
        return generateTrees(1, n, memo);
    }
    vector<TreeNode*> generateTrees(int st, int en, vector<vector<vector<TreeNode *>>> &memo) {
        if (st > en) return {};
        if (!memo[st][en].empty()) return memo[st][en];
        vector<TreeNode *> ans;
        for (int i = st; i <= en; ++i) {
            auto left_ans = generateTrees(st, i-1, memo), right_ans = generateTrees(i+1, en, memo); 
            if (left_ans.empty()) left_ans.push_back(nullptr);
            if (right_ans.empty()) right_ans.push_back(nullptr);
            for (auto l : left_ans) {
                for (auto r : right_ans) {
                    TreeNode *rt = new TreeNode(i);
                    rt->left = l;
                    rt->right = r;
                    ans.push_back(rt);        
                }
            }
        }
        return memo[st][en]=ans;
    }
};
```