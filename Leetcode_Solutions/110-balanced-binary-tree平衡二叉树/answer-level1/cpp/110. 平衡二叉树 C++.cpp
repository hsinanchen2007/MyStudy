### 解题思路
1.与求二叉树的高度类似，使用递归调用不断查找左右子树的高度，一旦发现不平处就返回-1。
2.-1数据会不断向上回传知道起始函数。

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
    int depth(TreeNode* root){
        if(root == NULL) return 0;
        int left = depth(root->left);
        if(left == -1) return -1;
        int right = depth(root->right);
        if(right == -1) return -1;
        return abs(left - right) < 2 ? max(left,right) + 1 : -1;
    }
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
};
```