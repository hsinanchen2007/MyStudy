先右后中再左，每次从栈中弹出节点，其值累加到后面弹出的节点上即可，
C++代码如下：
```c++
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> mystack;
        TreeNode* cur = root;
        int add = 0;
        while(cur != nullptr || !mystack.empty())
        {
            if(cur != nullptr)
            {
                mystack.push(cur);
                cur = cur->right;
            }
            else
            {
                cur = mystack.top();
                mystack.pop();
                cur->val += add;
                add = cur->val;
                cur = cur->left;
            }
        }
        return root;
    }
};