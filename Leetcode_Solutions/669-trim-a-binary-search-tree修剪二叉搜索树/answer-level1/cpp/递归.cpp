### 解题思路
二叉搜索树BST的特点：左节点 <=根节点  右节点 > 根节点
当节点的值 root->val < L时，所有的左节点肯定都是小于L,只有右节点才是有效节点
当节点的值 root->val > R 时，所有的右节点肯定都是大于L,只有左节点才是有效节点
当节点的值 root->val 在[L,R]之间时，当前节点和左右的节点都是有效节点

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root){
            return NULL;
        }
        //该节点满足要求
        if(root->val >= L && root->val <= R){
            //当前节点有效,左右节点可能有效
            root->left = trimBST(root->left,L,R);
            root->right = trimBST(root->right,L,R);
            return root;
        }
        else if(root->val < L){ //当前节点无效,只有右边的节点满足
            return trimBST(root->right,L,R);
        }
        else{ //当前节点无效,只有左边的节点满足
            return trimBST(root->left, L,R);
        }
        return NULL;
    }
};
```