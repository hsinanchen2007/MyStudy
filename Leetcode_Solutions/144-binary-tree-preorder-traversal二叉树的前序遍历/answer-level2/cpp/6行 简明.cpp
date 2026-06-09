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
vector <int> T;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root){
            T.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }     
        return T;
    }
};
```