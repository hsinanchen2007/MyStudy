### 解题思路
给定一个二叉树根节点，验证其是否为平衡二叉树：
- 首先求出该跟节点的左右子树的高度（递归求，可参考[104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)，附[题解](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/di-gui-shi-xian-zuo-you-zi-shu-bu-wei-kong-shi-di-/)）。若左右子树高度相差超过`1`，则不是平衡二叉树
- 若不超过`1`，递归验证其左子树和右子树是否为一棵平衡二叉树

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
    //给出根节点，求出该树的高度
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int left_len = 0, right_len = 0;
        if(root->left) left_len = dfs(root->left); // 求出左子树高度
        if(root->right) right_len = dfs(root->right); // 求出右子树高度
        return max(left_len, right_len) + 1; // 当前的高度等于左右子树高度最高的加1
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int left_len = dfs(root->left);
        int right_len = dfs(root->right);
        if(abs(left_len - right_len) > 1) return false;
        // 验证其左子树和右子树是否都为平衡二叉树
        else{
            if(isBalanced(root->left) == false || isBalanced(root->right) == false)
                return false;
        }
        return true;
    }
};
```