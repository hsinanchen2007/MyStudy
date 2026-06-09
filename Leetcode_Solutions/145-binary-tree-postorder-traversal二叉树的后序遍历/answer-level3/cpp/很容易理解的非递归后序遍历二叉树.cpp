### 解题思路

- 先压栈root；
- 如果右孩子存在那么压栈右孩子，如果左孩子存在那么压栈左孩子，直到栈顶的左右孩子皆为空或者栈顶节点是上一次出栈的父节点。

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
        vector<int> rst;
        if (!root) return rst;
        stack<TreeNode*> nodeStack;
        TreeNode *pre = nullptr;
        nodeStack.push(root);
        
        while (!nodeStack.empty()) {
            TreeNode *cur = nodeStack.top();
            if ((cur->left == nullptr && cur->right == nullptr) || (pre != nullptr && (pre == cur->left || pre == cur->right))) {
                nodeStack.pop();
                pre = cur;
                rst.push_back(cur->val);
            } else {
                if (cur->right != nullptr) {
                    nodeStack.push(cur->right);
                }
                if (cur->left != nullptr) {     
                    nodeStack.push(cur->left);
                }
            }
        }
        
        return rst;
    }
};
```