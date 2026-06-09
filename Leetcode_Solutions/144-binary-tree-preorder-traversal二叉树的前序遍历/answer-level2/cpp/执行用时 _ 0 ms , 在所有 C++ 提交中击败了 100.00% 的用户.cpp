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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int>res;
        TreeNode * temp = root;
	    stack<TreeNode*>s;
	    while (temp || !s.empty())
	    {
            while (temp) //一直向左将沿途结点压入栈
            {
                s.push(temp);
                res.push_back(temp->val);
                temp = temp->left;
            }
            if (!s.empty())
            {
                temp = s.top();
                s.pop();
                temp = temp->right;
            }
	    }
        return res;

    }
};
```