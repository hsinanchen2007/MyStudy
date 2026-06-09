### 解题思路
因为是二叉搜索树，中序遍历即可得到有序数组（用的递归方法），在遍历时使用一个计数器，自增到k时即可返回
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
    int kthSmallest(TreeNode* root, int k) {
        int res;
        int count = 0;
        traverse(root, k, count, res);
        return res;
    }
    void traverse(TreeNode* root, int k, int &count, int &res) {
        if (!root) return;
        traverse(root->left, k, count, res);
        count++;
        if (count == k) {
            res = root->val;
            return;
        }
        traverse(root->right, k, count, res);
    }
};
```