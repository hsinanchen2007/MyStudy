```cpp
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
    vector<TreeNode*> helper(TreeNode** root, const set<int>& s) {
        if (*root == NULL) return {};
        auto lnodes = helper(&(*root)->left, s);
        auto rnodes = helper(&(*root)->right, s);
        if (s.count((*root)->val)) {
            *root = NULL;
            lnodes.insert(lnodes.end(), rnodes.begin(), rnodes.end());
            return lnodes;
        }
        if (!lnodes.empty() && lnodes.back() == ((*root)->left)) lnodes.pop_back();
        if (!rnodes.empty() && rnodes.back() == ((*root)->right)) rnodes.pop_back();
        lnodes.insert(lnodes.end(), rnodes.begin(), rnodes.end());
        lnodes.push_back(*root);
        return lnodes;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> s(to_delete.begin(), to_delete.end());
        return helper(&root, s);
    }
};
```

![image.png](https://pic.leetcode-cn.com/9ca5cf2bb3fc477612fef8bda64b3e29f75cdb8e121ba1408dd85e157789f43f-image.png)
