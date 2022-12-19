### 解题思路
从左边开始递归入栈，直到没有左节点，然后把栈中弹出一个节点，存入vector，然后判断其是否有右节点，如果有，重复上述操作

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
        if (NULL == root)
        {
            return res;
        }
        stack<TreeNode *> s;
        TreeNode *temp = root;
        while(temp || !s.empty())
        {
            while(temp)
            {
                s.push(temp);
                temp = temp->left;
            }
            TreeNode *temp2 = s.top();
            res.push_back(temp2->val);
            s.pop();
            temp = temp2->right;
        }
        return res;
    }
};
```