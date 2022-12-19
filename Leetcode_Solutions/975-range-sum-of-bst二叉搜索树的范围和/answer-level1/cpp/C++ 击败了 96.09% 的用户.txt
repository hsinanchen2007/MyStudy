### 解题思路
![`XKYY(NR\]4@8S7CRL6BZFN4.png](https://pic.leetcode-cn.com/4b84c48e13ebf60ad7cd9cb3b2c512b158f020c8fae4f64517b1c9900b82ad3f-%60XKYY\(NR%5D4@8S7CRL6BZFN4.png)

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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == NULL)return 0;

        if (root->val < L)return rangeSumBST(root->right, L, R);
        else if (root->val > R)return rangeSumBST(root->left, L, R);
        else return root->val + rangeSumBST(root->right, L, R) + rangeSumBST(root->left, L, R);
    }
};
```