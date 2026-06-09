### 解题思路
先处理子树，子树返回自身左最大和右最大
当前节点使用右子树的左最大， 和左子树的右最大构造自身的返回结果

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
    int maxlen = 0;
    int longestZigZag(TreeNode* root) {
        vector<int> ret = func(root);
        maxlen = max(maxlen, max(ret[0], ret[1]));
        return maxlen;
    }
    vector<int> func(TreeNode* root) {
        if (!root) return {-1, -1};
        auto lret = func(root->left);
        auto rret = func(root->right);
        int curllen = lret[1] + 1;
        int currlen = rret[0] + 1;
        maxlen = max(maxlen, max(curllen, currlen));
        return {curllen, currlen};
    }
};
```