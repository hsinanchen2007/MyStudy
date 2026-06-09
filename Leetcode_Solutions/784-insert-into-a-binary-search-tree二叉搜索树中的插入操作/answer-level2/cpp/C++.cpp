### 解题思路
判断当前节点值和给定值之间的关系，
val < root->val ，到左子树中去查找, 如果左子树为空，直接挂上新节点即可; 不为空需要继续判断val和root->left->val之间的关系，递归搜索
val > root->val , 到右子树中去查找，方法类似
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
    void find(TreeNode* &root, int &val) {
        if(val < root->val) {
            // 小于根，到左子树中去找
            if (root->left == NULL) {
                // 左子树为空
                root->left = new TreeNode(val);
            } else {
                // 左子树不为空, 迭代查找
                find(root->left, val);
            }
        } else{
            // 到右子树中去找
            if (root->right == NULL) {
                root->right = new TreeNode(val);
            } else {
                find(root->right, val);
            }
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        find(root, val);
        return root;
    }
};
```