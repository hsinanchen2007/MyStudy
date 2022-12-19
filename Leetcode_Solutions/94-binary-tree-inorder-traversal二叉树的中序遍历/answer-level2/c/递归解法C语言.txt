### 解题思路
对于函数的形参:int* returnSize，第一遍看的时候不太懂他的作用，细看感觉应该是用指针变量来给输出的结果数组定位?相当于for(int a=0;a<arraySize;a++){arrat[a]=a;}中的a的作用？至于函数为什么要写这么一个参数还不太懂，希望有大佬解答

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



int TreeSize(struct TreeNode* root)
{
    if(!root)
        return 0;
    return TreeSize(root->left)+TreeSize(root->right)+1;
}


void inorder(struct TreeNode* root,int* returnSize,int* a)
{
    if(!root)
        return;
    inorder(root->left,returnSize,a);
    a[(*returnSize)++]=root->val;
    inorder(root->right,returnSize,a);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size=TreeSize(root);
    int* res=(int*)malloc(size*sizeof(int));
    memset(res,0,size);
    *returnSize=0;
    inorder(root,returnSize,res);
    return res;   


}
```