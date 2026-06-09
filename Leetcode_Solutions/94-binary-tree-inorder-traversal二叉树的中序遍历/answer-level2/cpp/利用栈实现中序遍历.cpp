### 解题思路
将整棵树的最左边一条链压入栈中，每次取出栈顶元素，如果它有右子树，则将右子树压入栈中。

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
        if(!root)
            return res;
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while(p|| stk.size())
        {
            while(p)
            {			
                stk.push(p);
                p=p->left;
            }
            p=stk.top();
            stk.pop();
            res.push_back(p->val);
            p=p->right;
        }
        return res;
    }
};
```