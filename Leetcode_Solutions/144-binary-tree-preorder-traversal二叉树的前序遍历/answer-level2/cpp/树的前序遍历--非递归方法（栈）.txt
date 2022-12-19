### 解题思路
非递归的方法：主要考虑什么时候输出；

关键点：
（1）前序入栈就输出，中序出栈在输出，后续需要访问第二次，出栈在输出。      
    while(cur != NULL) {
        stack.push(cur);
        vec.push_back(cur->val);
        cur = cur->left;
    }
（2）cur = cur->right; 无需判断右子树空与否


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
        std::stack<TreeNode*> stack;
        vector<int> vec;
        TreeNode* cur = root;
        while(cur != NULL || !stack.empty()) {
            while(cur != NULL) {
                stack.push(cur);
                vec.push_back(cur->val);
                cur = cur->left;
            }
            cur = stack.top();
            stack.pop();
            cur = cur->right;
        }
        return vec;
    }
};
```