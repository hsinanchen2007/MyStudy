### 解题思路
全局变量max不能在外赋值，会引起答案错误，在diameterOfBinaryTree函数内赋值
解体基本思路是：
    对于二叉树的每一个结点进行遍历，以此计算出该结点左右子树深度，相加可得以该结点为拐点得最大路径
    比较以每个结点为拐点的最大路径，取最大值就是结果

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
int max;
int counthigh(struct TreeNode* root);
int countdis(struct TreeNode* root);
void preordertree(struct TreeNode* root);

int diameterOfBinaryTree(struct TreeNode* root){
    max=0;
    if(!root||(!root->left&&!root->right))
        return 0;
    preordertree(root);


    return max;
}

void preordertree(struct TreeNode* root)
{
    if(root)
    {
        int count=countdis(root);
        if(max<count)
            max=count;
    }
    else
        return;
    preordertree(root->left);
    preordertree(root->right);
    return;
}

//统计以每个结点为转折得最大路径长度
int countdis(struct TreeNode* root)
{
    if(!root)
        return 0;
    int res=0;
    int left=counthigh(root->left);
    int right=counthigh(root->right);

    res=left+right;

    return res;
}
int counthigh(struct TreeNode* root)
{
    if(!root)
        return 0;
    int left=0;
    if(root->left!=NULL)
        left=counthigh(root->left);
    int right=0;
    if(root->right!=NULL)
        right=counthigh(root->right);
    int height=(left>right?left:right)+1;
    return height;
}
```