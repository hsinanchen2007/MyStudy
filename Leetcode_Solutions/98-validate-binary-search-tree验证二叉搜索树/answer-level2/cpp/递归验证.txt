### 解题思路
- 从根节点出发，递归验证**左子树**的**所有**节点的值是否小于根节点的值，递归验证**右子树**的**所有**节点的值是否大于根节点的值
- 再对根的**左子树节点**进行和**右子树节点**进行和根节点一样的验证


代码容易看懂


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

    bool validate_left_tree(TreeNode* root, int val){
        if(root->val >= val) return false;
        if(root->left){
            if(!validate_left_tree(root->left, val)) return false;
        }
        if(root->right){
            if(!validate_left_tree(root->right, val)) return false;
        }
        return true;
    }

    bool validate_right_tree(TreeNode* root, int val){
        if(root->val <= val) return false;
        if(root->left){
            if(!validate_right_tree(root->left, val)) return false;
        }
        if(root->right){
            if(!validate_right_tree(root->right, val)) return false;
        }
        return true;
    }

    bool dfs(TreeNode* root, int val){
        if(root->left){
            if(!validate_left_tree(root->left, val)) return false;
            if(!dfs(root->left, root->left->val)) return false;
        }
        if(root->right){
            if(!validate_right_tree(root->right, val)) return false;
            if(!dfs(root->right, root->right->val)) return false;
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return dfs(root, root->val);
    }
};
```