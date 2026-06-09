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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> printResult;
        
        if (root == NULL) 
            return printResult;

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            vector<int> print;
            int l = q.size();
            for (int i=0; i<l; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                print.push_back(node->val);

                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            printResult.push_back(print);
        }

        return printResult;
    }
};
```