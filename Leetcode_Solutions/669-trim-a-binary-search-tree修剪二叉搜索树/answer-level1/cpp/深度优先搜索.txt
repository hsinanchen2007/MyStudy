### 解题思路
深度优先遍历树，先修剪左子树，再修剪右子树，如果此时节点需要修剪，就把左子树或右子树移到当前节点。
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
    TreeNode* sheer(TreeNode* root, int L, int R)
    {
        if(root == NULL) return NULL;  //递归边界
        root -> left = sheer(root -> left, L, R);  //修剪左子树
        root -> right = sheer(root -> right, L, R);  //修剪右子树
        if(root -> val < L || root -> val > R)
        root = root -> right == NULL ? root -> left : root -> right;  //修剪子树根节点
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        TreeNode* ans = NULL;
        if(root == NULL) return ans;
        ans = sheer(root, L, R);
        return ans;
    }
};
```