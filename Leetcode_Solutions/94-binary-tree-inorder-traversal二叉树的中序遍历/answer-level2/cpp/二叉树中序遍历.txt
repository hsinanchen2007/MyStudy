### 解题思路
仍需深入贯彻领会中序遍历精神

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
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *node, *curr = root;

        while((!stk.empty()) || curr){
            while(curr){
                stk.push(curr);
                curr = curr->left;
            }
            node = stk.top();  stk.pop();
            if(node) res.push_back(node->val);
            if(node->right)  curr = node->right;
        }

        return res;
    }
};
```