### 解题思路
c++

### 代码

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode *cur = root;
        while(cur || !s.empty()) {
            if (cur != NULL) {
                ret.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            }
            else {
                cur = s.top();
                s.pop();
                cur = cur->right;
            }
        }
        return ret;
    }
};
```