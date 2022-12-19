### 解题思路
用队列实现广度优先搜索

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty())
        {
            root=qu.front();
            qu.pop();
            if(root->right!=NULL) 
            qu.push(root->right);
            if(root->left!=NULL) 
            qu.push(root->left);
        }
        return root->val;
    }
};
```