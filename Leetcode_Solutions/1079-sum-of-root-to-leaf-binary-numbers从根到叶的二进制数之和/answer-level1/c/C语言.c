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



int num;

void _sumRootToLeaf(struct TreeNode *root, int sum)
{
    if(root == NULL)
        return;

    //if(root->left == NULL && root->right == NULL)
       // num += sum;
   
    sum = (sum << 1) + root->val;
    if(root->left == NULL && root->right == NULL)
        num += sum;
    printf("%d ", sum);
    _sumRootToLeaf(root->left, sum);
    _sumRootToLeaf(root->right, sum);

}


int sumRootToLeaf(struct TreeNode *root)
{
    int sum = 0;
    num = 0;
    _sumRootToLeaf(root, sum);
    return num;
}
```