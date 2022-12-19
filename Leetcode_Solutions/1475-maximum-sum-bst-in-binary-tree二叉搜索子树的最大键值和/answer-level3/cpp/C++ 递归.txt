### 解题思路
参考了@失火的夏天的题解。
1. 判断是否为二叉搜索树；
2. 树键值的求和；
3. 遍历寻找最大值。
每对BST做一次求和，就更新一下答案

![图片.png](https://pic.leetcode-cn.com/7137c3030c071d5b22a2699e79fe436aebb5e06c14b2fc1fdd8c051f7c0fb142-%E5%9B%BE%E7%89%87.png)


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
    int maxSum{0};

    bool isBST(TreeNode* root, int minBord, int maxBord) {
        if (!root) {
            return true;
        }
        return minBord < root->val && root->val < maxBord && isBST(root->left, minBord, root->val) && isBST(root->right, root->val, maxBord);
    }

    int SumTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sum = root->val + SumTree(root->left) + SumTree(root->right);
        maxSum = max(sum, maxSum);
        return sum;
    }

    void maxSumBSTHelper(TreeNode* root) {
        if (isBST(root, INT_MIN, INT_MAX)) {
            (void) SumTree(root);
            return ;
        }
        maxSumBSTHelper(root->left);
        maxSumBSTHelper(root->right);
    }

    int maxSumBST(TreeNode* root) {
        maxSumBSTHelper(root);
        return maxSum;
    }
};
```