## 要求
在二叉树的后序遍历中，常常依靠队列，要么在队列中前向插入，要么利用队列去判断该节点是否遍历过，现在要求只能利用栈去做，不能用队列去辅助判断（即，只允许在队列尾部添加答案）

## 思路
这道题的难点在于仅利用栈去判断该节点是否为父结点，创新性思路是每次在栈中压入父节点后压入`nullptr`，之后再依次压入右子节点和左子节点。

## 代码
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
        if (root == nullptr) return {};
        stack<TreeNode*> stk;
        stk.push(root);
        vector<int> res;
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            if (node == nullptr) {
                stk.pop();
                res.push_back(stk.top()->val);
                stk.pop();
                continue;
            }
            stk.push(nullptr);
            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }
        return res;
    }
};
```
