### 解题思路
本题主要利用BST的中序遍历时得到的结果有序的情况下，
使用递归参数保存在有序情况下每个结点的上一个结点(pre)与下一个结点(last)的指针，
遍历结点时，比对前后结点与当前结点的距离，获取最小差距
后续递归左右子树时，需调整其上下限结点

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
    int minDiffInBST(TreeNode* root) {
        int min_diff = INT_MAX;
        helper(root, nullptr, nullptr, min_diff);
        return min_diff;
    }

    void helper(TreeNode* root, TreeNode* pre, TreeNode* last, int& diff) {
        if (root == nullptr) {
            return;
        }
        // pre与last指定上下限结点
        if (pre) {
            diff = min(diff, root->val - pre->val);
        } 

        if (last) {
            diff = min(diff, last->val - root->val);
        }
        helper(root->left, pre, root, diff);
        helper(root->right, root, last, diff);
    }
};
```