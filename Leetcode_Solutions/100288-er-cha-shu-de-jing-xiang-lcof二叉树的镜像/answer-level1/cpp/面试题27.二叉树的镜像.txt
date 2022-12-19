### 解题思路
核心思路：递归左右子树进行镜像处理，然后交换根节点的左右指针
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.1 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        if(root->left!=NULL){
            root->left=mirrorTree(root->left);
        }
        if(root->right!=NULL){
            root->right=mirrorTree(root->right);
        }
        TreeNode*tmp=root->left;
        root->left=root->right;
        root->right=tmp;
        return root;
    }
};
```