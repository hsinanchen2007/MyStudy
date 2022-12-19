### 解题思路
第一种情况：被删除结点是叶节点，直接删除，毫无影响
第二种情况：被删除结点有一颗左子树，直接返回左子树，若有右子树，直接返回右子树
第三种情况：左右子树都有，找到该结点右子树的最左结点，将该结点的左子树变成最左结点的左子树，返回该结点的右子树

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }
        if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else{
            if(!root->left){
                return root->right;
            }
            if(!root->right){
                return root->left;
            }
            TreeNode * small_left = root->right;
            while(small_left->left){
                small_left = small_left->left;
            }
            small_left->left = root->left;
            return root->right;
        }
        return root;
    }
};
```