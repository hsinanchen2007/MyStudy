### 解题思路
递归即可

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root==NULL)return new TreeNode(val);
        if(root->val>val){
            TreeNode *tmp = insertIntoMaxTree(root->right,val);
            root->right = tmp;
            return root;
        }else{
            TreeNode *tmp = new TreeNode(val);
            tmp->left = root;
            return tmp;
        }
    }
};
```