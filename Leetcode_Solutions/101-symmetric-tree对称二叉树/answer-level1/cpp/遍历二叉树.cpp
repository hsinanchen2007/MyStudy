### 解题思路
递归每个root，逐渐向下遍历。

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
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr)return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* root1,TreeNode* root2){
        if(root1==nullptr && root2==nullptr)return true;
        
        else if ( (root1!=nullptr && root2==nullptr) || (root2!=nullptr && root1 == nullptr) ) return false;
        
        else if (root1->val==root2->val){
            return isSymmetric(root1->left, root2->right) && isSymmetric(root2->left, root1->right);
        }
        
        else if(root1->val!=root2->val) return false;//root1->val!=root2->val

        return false;
    }
};
```