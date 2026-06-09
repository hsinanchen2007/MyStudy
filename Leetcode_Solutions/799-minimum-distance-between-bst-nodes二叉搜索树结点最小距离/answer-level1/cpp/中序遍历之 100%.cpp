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
    int minDiffInBST(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int result = INT_MAX;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* cur = root, *lastcur = cur;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            result = min(result, cur->val>lastcur->val? cur->val-lastcur->val : INT_MAX);
            lastcur = cur;
            cur = cur->right;
        }
        return result;
    }
};
```
![Screen Shot 2019-12-06 at 10.50.41 AM.png](https://pic.leetcode-cn.com/0d7a3231ea38c95060d3f8f48dd57a2b83990182b26236a5d372f075cc2c9f85-Screen%20Shot%202019-12-06%20at%2010.50.41%20AM.png)
