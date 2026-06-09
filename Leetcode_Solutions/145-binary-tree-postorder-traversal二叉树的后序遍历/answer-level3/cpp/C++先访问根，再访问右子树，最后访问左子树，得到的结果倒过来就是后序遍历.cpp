### 解题思路
先访问根，再访问右子树，最后访问左子树，得到的结果倒过来就是后序遍历

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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans_vec;        
        if(!root) return ans_vec;

        stack<TreeNode*> node_stack;
        stack<int> ans_stk;
        TreeNode* node = nullptr;
        node_stack.push(root);

        while(node_stack.size())
        {
            node = node_stack.top();
            node_stack.pop();
            ans_stk.push(node -> val);
            if(node -> left) node_stack.push(node -> left);
            if(node -> right) node_stack.push(node -> right);
        }
        while(ans_stk.size())
        {
            ans_vec.push_back(ans_stk.top());
            ans_stk.pop();
        }
        return ans_vec;
    }
};
```