### 解题思路
此处撰写解题思路

执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :7.7 MB, 在所有 C 提交中击败了100.00%的用户

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    int left, right;
    
    if (root == NULL) {
        return 0;
    }
    
    left = maxDepth(root->left) + 1;
    right = maxDepth(root->right) + 1;
    
    return left > right ? left : right;
}

```