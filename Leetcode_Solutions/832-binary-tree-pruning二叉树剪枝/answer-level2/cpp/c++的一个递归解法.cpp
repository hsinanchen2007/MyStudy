### 解题思路
思路见注释

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
    TreeNode* pruneTree(TreeNode* root) {
        if(root) {
            root->left = pruneTree(root->left);  //递归左孩子
            root->right = pruneTree(root->right); //递归右孩子
            //判断是否需要剪枝的条件      
            if(!root->left && !root->right && !root->val) {//有两种类型的进入这个if条件 执行剪枝
                //1.叶子节点，且val为0 2.非叶子节点，左右孩子都已被剪枝且val为0 
                return NULL;                    
            } 
            return root;
        }
        return NULL;
    }
};