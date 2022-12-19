### 解题思路
通过设置不同的d值，区分放到左子树还是右子树，然后递归的生成左右子树

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d==0 || d==1){
            TreeNode* t = new TreeNode(v);
            if (d==1) t->left=root;//1在左子树，0在右子树   
            else t->right=root;
            return t;
        }
        if (root != NULL && d>1){
            if (d>2){
                root->left=addOneRow(root->left, v, d-1);
                root->right=addOneRow(root->right, v, d-1);
            }
            else{
                root->left=addOneRow(root->left, v, 1);
                root->right=addOneRow(root->right, v, 0);
            }
        }
        return root;
    }
};
```