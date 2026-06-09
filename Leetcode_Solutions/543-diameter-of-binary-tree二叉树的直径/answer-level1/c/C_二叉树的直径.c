### 解题思路
1.最长路径可能是子树中的，不一定过根节点。
2.记录最长点的int不能声明为全局变量（如注释掉的代码），否则每次测试会保留上一个测试用例的直径。如果上一次直径比这一次大，这一次输出的结果是上一个测试用例的结果。

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

int deep(struct TreeNode* root,int* Max)
{
    if(root==0)return 0;
    int left=deep(root->left,Max);
    int right=deep(root->right,Max);
    *Max=*Max>(left+right)?*Max:(left+right);
    return left>right?left+1:right+1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    if(root==0)return 0;
    int max=-1;
    deep(root,&max);
    return max;
}

/*不可以这样记录最大直径

int MAX=0;

int deep(struct TreeNode* root)
{
    if(root==0)return 0;
    int left=deep(root->left);
    int right=deep(root->right);
    MAX=MAX>(left+right)?MAX:(left+right);
    return left>right?left+1:right+1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    if(root==0)return 0;
    deep(root);
    return MAX;
}*/
```