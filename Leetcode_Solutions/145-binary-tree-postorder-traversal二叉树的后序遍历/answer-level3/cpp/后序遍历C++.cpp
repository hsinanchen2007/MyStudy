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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode *curr = root;
        stack<TreeNode*> s;
        stack<bool> flag;

        while(curr || !s.empty()) {
            if (curr != NULL) {
                s.push(curr);
                flag.push(false);
                curr = curr->left; //无左跳下
            }
            else {
                curr = s.top();
                if (curr->right == NULL || flag.top()) {
                    ret.push_back(curr->val);
                    s.pop();
                    flag.pop();
                    curr = NULL;
                } else {
                    curr = curr->right;
                    flag.pop();
                    flag.push(true);
                }
                

            }
        }
        return ret;
    }
};
```