```
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            for (int i = 0, sz = queue.size(); i < sz; ++i) {
                if (i == 0) res.push_back(queue.front()->val);
                if (queue.front()->right != NULL) queue.push(queue.front()->right);
                if (queue.front()->left  != NULL) queue.push(queue.front()->left );
                queue.pop();
            }
        }
        return res;
    }
};
```
