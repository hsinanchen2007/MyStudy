### 解题思路
此处撰写解题思路

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
        if(root == NULL)//出口为0
            return 0;
        int leftDepth = maxDepth(root->left);//向左
        int rightDepth = maxDepth(root->right);//向右
        return (leftDepth > rightDepth) ? (leftDepth+1):(rightDepth+1);//递归
    }
};
//非空根节点，其深度等于左子树和右子树的深度二者之间较大者+1；


```