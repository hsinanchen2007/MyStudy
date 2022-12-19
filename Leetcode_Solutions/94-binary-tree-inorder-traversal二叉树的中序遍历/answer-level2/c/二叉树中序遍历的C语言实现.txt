### 解题思路
该题属于常规题目，二叉树的问题基本都需要用到递归，解题方法如下：
* 入参检查
* 获取二叉树的节点个数
* 动态分配并初始化数组
* 运用递归，中序遍历该二叉树

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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(struct TreeNode *root, int *returnSize, int *res)
{
    if(!root)
    {
        return;
    }
    inorder(root->left,returnSize,res);
    res[(*returnSize)++] = root->val;
    inorder(root->right, returnSize,res);
}

int nodeNum(struct TreeNode *root)
{
    if(!root)
    {
        return 0;
    }
    return nodeNum(root->left)+nodeNum(root->right)+1;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    //入参检查
    if(!root)
    {
        *returnSize = 0;
        return NULL;
    }
    //递归
    int len = nodeNum(root);
    int *result = (int*)malloc(sizeof(int)*len);
    memset(result,0,sizeof(int)*len);
    *returnSize = 0;
    inorder(root, returnSize, result);
    return result;
}
```