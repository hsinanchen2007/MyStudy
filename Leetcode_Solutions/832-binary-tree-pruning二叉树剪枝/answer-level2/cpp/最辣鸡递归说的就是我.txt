先剪左，剪完判断是否是秃子0（没有左头发和右头发且值为0）；
后剪右，再判断。
```
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
    void pt(TreeNode *p) {
        if (!p) {
            return;
        }
        TreeNode *pl = p->left;
        TreeNode *pr = p->right;
        if (pl) {
            pt(pl); //左不为空，剪左
            if (!pl->left && !pl->right && !pl->val) { //是否是秃子0
                p->left = NULL;
            }
        }
        if (pr) {
            pt(pr);
            if (!pr->left && !pr->right && !pr->val) {
                p->right = NULL;
            }
        }
    }

    TreeNode *pruneTree(TreeNode *root) {
        TreeNode *p = root;
        pt(p);
        return root;
    }
};
```
