### 解题思路
纯C++ 

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
        if (NULL == root)
        {
            return {};
        }

        deque<int> res;
        stack<TreeNode*> s;

        s.push(root);

        while (false == s.empty())
        {
            TreeNode* node = s.top();
            s.pop();

            res.push_front(node->val);

            if (node->left)
            {
                s.push(node->left);
            }

            if (node->right)
            {
                s.push(node->right);
            }
        }

        return vector<int>(res.begin(), res.end());
    }
};
```