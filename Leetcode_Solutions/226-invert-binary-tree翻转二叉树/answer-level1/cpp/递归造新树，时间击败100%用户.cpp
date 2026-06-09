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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* newTree = new TreeNode(0);
        return invertTree(newTree,root);
    }
private:
    TreeNode* invertTree(TreeNode* newTree,TreeNode* root){
        //针对 空的root 和 叶节点指向的nullptr
        if(!root) return nullptr;
        //针对 叶节点
        newTree->val = root->val;
        //针对 右子树
        if(root->right){
            TreeNode* left = new TreeNode(0);
            newTree->left = invertTree(left,root->right);
        }
        //针对 左子树
        if(root->left){
            TreeNode* right = new TreeNode(0);
            newTree->right = invertTree(right,root->left); 
        }
        return newTree;       
    }
};
```

![image.jpeg](https://pic.leetcode-cn.com/75d596c97079fc5648c35cfd4e2f39b40807b7b5b0dd881738d1189c23fa1655-image.jpeg)

造个新树不就好了？？万一不行把原来的树删掉，不就相当于翻转了这棵树。
