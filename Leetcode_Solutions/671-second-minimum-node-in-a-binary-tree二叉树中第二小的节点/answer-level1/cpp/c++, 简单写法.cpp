### 解题思路
主要在第一次匹配上,用这个flag将不是root->val进行赋值
这个过程中可能会将较大的值赋上,此时需要看是否有其他值比这个值小,
如果有进行更换;
因为该树孩子节点值只能大于等于父节点,故如果子节点大于res,直接返回即可;

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
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }
        int res = -1;
        bool first_matched = true;
        DFS(root, root->val, res, first_matched);
        return res;
    }
    void DFS(TreeNode* root, int root_val, int& res, bool& matched) {
        if (root == NULL) {
            return ;
        }
        if (root->val != root_val) {
            if (matched) {
                res = root->val;
                matched = false;
            } else if (root->val < res) {
                res = root->val;
            } else {
                return ;
            }
        }
        DFS(root->left, root_val, res, matched);
        DFS(root->right, root_val, res, matched);
    }
};
```