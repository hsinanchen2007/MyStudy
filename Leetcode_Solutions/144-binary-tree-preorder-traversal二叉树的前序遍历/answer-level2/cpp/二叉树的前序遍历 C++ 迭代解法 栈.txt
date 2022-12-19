### 解题思路
此处撰写解题思路

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
        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode* temp = root;
        while (temp != NULL || !stk.empty()) {
            while (temp != NULL) {
                res.push_back(temp -> val);
                stk.push(temp);
                temp = temp -> left;
            }
            temp = stk.top();
            stk.pop();
            temp = temp -> right;
        }
        return res;
    }
};












```