### 解题思路
该题的思路比较清晰，利用递归求节点左右子树长度。但是，该题需要求对比每个节点的直径，并返回最大值。
因此，借鉴官方题解的代码，设置了一个全局变量，利用该全局变量保存每个节点直径的最大值。

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

//思路：求左右子树的最大深度
//maxDepth求树的深度
//递归
//终止条件
//叶节点终止

int ans;

int maxDepth(struct TreeNode *root)
{
    //终止条件
    if(!root)
    {
        return 0;
    }

    //开始递归
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    ans = ans > (left+right+1) ? ans : (left+right+1);
    return ((left > right ? left : right)+1);
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    ans = 1;
    //入参检查
    if(!root)
    {
        return 0;
    }

    maxDepth(root);

    //求和
    return (ans-1);

}
```