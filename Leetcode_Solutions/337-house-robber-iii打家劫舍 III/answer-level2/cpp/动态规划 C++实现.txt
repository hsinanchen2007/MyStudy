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
private:
public:
    pair<int, int> rob_internal(TreeNode * root){
        if(!root) return {0, 0};
        pair<int, int> umpVal;

        if(!root->left && !root->right) {
            umpVal = {root->val, 0};
        } else {
            pair<int, int> a = rob_internal(root->left);
            pair<int, int> b = rob_internal(root->right);
            int fst = max(root->val + a.second + b.second, a.first + b.first);
            int snd = a.first + b.first;
            umpVal = {fst, snd};
        }

        return umpVal;
    }

    int rob(TreeNode* root) {
        pair<int, int> robVal = rob_internal(root);
        return max(robVal.first, robVal.second);
    }
};
```