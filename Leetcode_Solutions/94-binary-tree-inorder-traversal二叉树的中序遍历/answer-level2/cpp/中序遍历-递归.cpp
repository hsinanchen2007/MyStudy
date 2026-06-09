### 解题思路
使用递归算法

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
    vector<int>result;//这里要是全局变量

    vector<int> inorderTraversal(TreeNode* root) {
       
        if(root == NULL)
        {
            return result;
        }
        inorderTraversal(root->left);

        result.push_back(root->val);

        inorderTraversal(root->right);

        return result;//一定要有返回值
        
    }
     
};
```