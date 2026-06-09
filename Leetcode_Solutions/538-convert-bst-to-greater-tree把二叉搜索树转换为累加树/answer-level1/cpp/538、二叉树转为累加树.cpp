### 解题思路
右中左采用递归遍历，辅助变量求和

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
private:
    int temp;
public:
    void getData(TreeNode* root){
        if(!root){
            return;
        }
        convertBST(root->right);
        temp += root->val;
        root->val = temp;
        convertBST(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        getData(root);
        return root;
    }
};
```