### 解题思路
类似题目：124. 二叉树中的最大路径和
int maxPath(TreeNode* root)返回以root为端点的最大路径（不包括穿过root节点的路径）
每次计算一个节点的maxPath后，也计算一下cross穿过root节点的路径长度，并更新maxLen

![image.png](https://pic.leetcode-cn.com/87572a3e175229003191ec64e9c5c720ce3c92ca513a36423ccd73a24a283de9-image.png)


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
    int maxLen{0};

    int maxPath(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = (root->left) ? maxPath(root->left) + 1 : 0;
        int right = (root->right) ? maxPath(root->right) + 1 : 0;
        int cross = left + right;
        int ans = max(left, right);
        maxLen = max(ans, maxLen);
        maxLen = max(cross, maxLen);
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root || (!root->left && !root->right)) {
            return 0;
        }
        maxPath(root);
        return maxLen;
    }
};
```