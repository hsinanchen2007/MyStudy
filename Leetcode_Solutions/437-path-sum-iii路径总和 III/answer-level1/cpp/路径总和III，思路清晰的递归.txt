### 解题思路
1、首先想到一种较为简单的情况，求从根节点root出发，所有路径和等于sum的不同路径条数；写出该辅助函数void path(TreeNode* root, int sum, int& num)//sum为目标和，num满足条件的不同路径数
2、在1的基础上，求从任意结点出发，所有路径和等于sum的不同路径条数；写出辅助函数
void path_sum_help(TreeNode* root, int sum, int& num)函数思路如下：
调用path(root),找出以root为起始点的路径数，
调用 path_sum_help(root->left)，找出以root->left为树根的路径数
调用 path_sum_help(root->right), 找出以root->right为树根的路径数
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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        int num = 0;
        path_sum_help(root, sum, num);
        return num;
    }

    void path_sum_help(TreeNode* root, int sum, int& num)//从任意结点出发，和等于sum的不同路径，路径终点不一定是叶节点
    {
        if(!root) return;
        path(root, sum, num);
        path_sum_help(root->left, sum, num);
        path_sum_help(root->right, sum, num);
    }
    void path(TreeNode* root, int sum, int& num)//从root出发，找到所有以root为起始点，和的值等于sum的不同路径，路径不一定到叶节点
    {
        if(!root) return;
        sum -= root->val;
        if(sum == 0)
            num++;

        path(root->left, sum, num);
        path(root->right, sum, num);
    }
};
```