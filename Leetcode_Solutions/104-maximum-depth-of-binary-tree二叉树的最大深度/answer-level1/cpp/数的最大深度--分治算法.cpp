### 解题思路
（1）要看当前函数返回值是不是够用，需要累计int，目测够用，无需新建递归函数
（2）分：左右子树的最大深度
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
（3）治：左右子树深度 + 根节点（1）是树的最大深度
（4）结束条件：
     //如果树为空，则表示树的深度为0 
     if(root == NULL) return 0;
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
    int maxDepth(TreeNode* root) {
        
        if(root == NULL) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;

    }
};
```