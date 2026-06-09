### 解题思路
此处撰写解题思路

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


// 求树高（递归）
int TreeHight(struct TreeNode *root){
    if(!root) return 0;
    int l_hight = TreeHight(root->left);
    int r_hight = TreeHight(root->right);
    return (l_hight>=r_hight?l_hight:r_hight)+1;
}

bool isBalanced(struct TreeNode* root){
    if(!root) return true; //如果为空返回true
    // 递归求高度
    int l_hight = TreeHight(root->left);
    int r_hight = TreeHight(root->right);
    // 是否符合定义 绝对值小于1
    if(l_hight-r_hight>1||r_hight-l_hight>1){
        return false;
    }
    // 递归判断是否符合
    return isBalanced(root->left) && isBalanced(root->right);
}

```