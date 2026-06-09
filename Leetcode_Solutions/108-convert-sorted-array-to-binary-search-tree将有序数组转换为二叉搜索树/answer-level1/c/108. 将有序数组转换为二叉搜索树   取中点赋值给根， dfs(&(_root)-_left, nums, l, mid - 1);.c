### 解题思路
１．高度平衡，　每个子树的左右　高度不高过１
２．所以对于每个子树，根都是前序遍历的中点，　递归找中点赋值给根

将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5



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

void dfs(struct TreeNode** root, int *nums, int l, int r){
    if (l > r)
        return;

    int mid = (l + r)/2;
    //printf("mid=%d l=%d r=%d\n",mid, l, r);
    *root = malloc(sizeof(struct TreeNode));
    
    (*root)->val = nums[mid];
    (*root)->left = NULL;
    (*root)->right = NULL;
    dfs(&(*root)->left, nums, l, mid - 1);    
    dfs(&(*root)->right, nums, mid + 1, r);
}


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){

    if (numsSize == 0)
        return NULL;

    struct TreeNode *root; 

    dfs(&root, nums, 0, numsSize -1);
    return root;
}
```