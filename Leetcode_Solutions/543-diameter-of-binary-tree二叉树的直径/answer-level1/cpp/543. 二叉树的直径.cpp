### 解题思路
ans = max{中间结点的左右子树的高的和}；
递归中间结点（从根结点开始），递归计算左右子树的高，用ans记录最大左右和。

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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int high = highTree(root, ans);
        return ans;
    }
    int highTree(TreeNode* root, int &ans) {
        if(root == NULL)
            return 0;
        int L = highTree(root->left, ans);
        int R = highTree(root->right, ans);
        ans = max(L + R, ans);

        return max(L, R) + 1;
    }
};
```
![11.png](https://pic.leetcode-cn.com/20e2cf81423a96837895785bbbb5da95e6aea3e1602e38dc483ab086faff842c-11.png)
