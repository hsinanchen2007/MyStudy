### 解题思路
递归思路很清晰，对于一个节点，不为空，则递归调用左右节点，调用结束，交互左右子节点。

迭代就是手动维护递归栈。递归调用前压栈，保存递归函数变量，出栈弹出保存的变量

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
    TreeNode* invertTree(TreeNode* root) {

        //help(root);//递归

        if(root == NULL) {
            return root;
        }
        TreeNode* cur = root;
        stack<TreeNode*> s;
        s.push(cur);
        while(!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            if(node != NULL) {
                s.push(node->right);
                s.push(node->left);
                swap(node->left, node->right);
            }
        }
        return root;
    }

    void help(TreeNode* root) {
        if(root == NULL)
            return;
        //开始入栈
        help(root->left);
        //出栈再入栈
        help(root->right);
        // TreeNode* tmp = root->left;
        // root->left = root->right;
        // root->right = tmp;
        //出栈后交互
        swap(root->left, root->right);
    }
};
```