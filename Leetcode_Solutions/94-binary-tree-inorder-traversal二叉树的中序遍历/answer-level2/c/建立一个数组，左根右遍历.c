### 解题思路
此处撰写解题思路
![11.png](https://pic.leetcode-cn.com/02d092eaa455841519e8fb6d51dea0190d3f3b08702d6a3165baed5c13838ea5-11.png)

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
int Tree_size(struct TreeNode* root)   //计算出树的全部节点，方便数组的开辟
{
    if(root == NULL)
        return 0;
    return 1 + Tree_size(root->left) + Tree_size(root->right);
}

void Creat(struct TreeNode* root, int* a, int* i) // 左 根 右
{
    if(root == NULL)
        return;
    Creat(root->left,a,i);
    a[(*i)++] = root->val;
    Creat(root->right,a,i);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size = Tree_size(root);
    int* a = (int*)malloc(sizeof(int) * size);
    *returnSize = size;
    int i = 0;
    Creat(root,a,&i);  //传i的地址，否则递归调用的i非此i
    return a;
}

```