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
int sum;//定义全局变量保存两子树深度和的最大值
int dfs(struct TreeNode* root)//求树的深度
{
    if(root == NULL)
    {
        return 0;
    }
    int a = dfs(root->left);
    int b = dfs(root->right);
    sum = sum > (a+b+1) ? sum : (a+b+1);//更新最大值
    return  (a > b ? a : b) + 1;
}
int diameterOfBinaryTree(struct TreeNode* root){
    if(root == NULL)
    {
        return 0;
    }
    sum = 0;
    dfs(root);
    return sum-1;//由于我前面加了个1，所以这里减，有点多此一举了，哈哈
}
```