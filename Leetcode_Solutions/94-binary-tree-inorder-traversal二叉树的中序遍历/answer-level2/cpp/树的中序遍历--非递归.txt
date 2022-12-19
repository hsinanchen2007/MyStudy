### 解题思路


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        std::stack<TreeNode*> stack;
        TreeNode* cur = root;
        while(cur != NULL || !stack.empty()) {
            while(cur != NULL) {
                stack.push(cur);
                cur = cur->left;
            }
            cur = stack.top();
            //中序的关键，在pop的时候输出
            vec.push_back(cur->val);
            stack.pop();
            cur = cur->right;
        }
        return vec;
    }
};
```