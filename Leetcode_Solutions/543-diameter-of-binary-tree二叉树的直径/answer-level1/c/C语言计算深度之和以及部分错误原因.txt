```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int length;//设置全局变量

int diameterOfBinaryTree(struct TreeNode* root)
{
    //只需要计算出深度之和的最大值
    length=0;
    deep(root);
    return length;
}

int deep (struct TreeNode* root)
{
    int max=0;     //当前树的深度
    int leftmax=0; //左子树的深度
    int rightmax=0;//
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        leftmax=deep(root->left);
        rightmax=deep(root->right);
        length=(length>=(leftmax+rightmax)?length:(leftmax+rightmax));
        return (leftmax>=rightmax?leftmax:rightmax)+1;//每次递归算深度
    }
}

```
参照大佬写的C++题解，用C语言与全局变量实现
一般计算二叉树的深度返回值用来操作深度，即为retuen的值必然为树的深度；
本题需要两者最大深度之和，使用全局变量实现；（全局变量每次使用之前要初始化）
 length=(length>=(leftmax+rightmax)?length:(leftmax+rightmax));记录直径的最大值；


