### 解题思路
记录最大值、最小值 以便与左右子树的所有节点进行比较，增加函数参数列表来实现。

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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,NULL,NULL);
    }

    bool isValidBST(TreeNode* root,TreeNode* min,TreeNode* max){
        if(root==NULL){
            return true;
        }
        if(min!=NULL&&root->val<=min->val){
            return false;
        }
        if(max!=NULL&&root->val>=max->val){
            return false;
        }
        return isValidBST(root->left,min,root)&&isValidBST(root->right,root,max);
    }
};
```