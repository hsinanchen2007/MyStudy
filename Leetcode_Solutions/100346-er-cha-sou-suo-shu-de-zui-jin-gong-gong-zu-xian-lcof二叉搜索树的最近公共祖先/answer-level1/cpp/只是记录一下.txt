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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
            与平凡的二差树相比，这里要多利用搜索树的特性
            主要的就是要比大小了，不要暴力的去遍历了
            root->val > (root->left && root->right)这就说明最近公共在left上
            或者root->val < (root->left, && root->right)这就说明最近公共在right上
            或者root本身就是
        */

        if (!root) return nullptr;  //base

        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        return root;


    }
};
```