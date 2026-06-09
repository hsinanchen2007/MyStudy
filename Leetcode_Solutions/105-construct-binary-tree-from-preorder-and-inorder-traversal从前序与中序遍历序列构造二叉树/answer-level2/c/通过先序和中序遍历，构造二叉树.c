### 解题思路

先序遍历的首元素，即为二叉树的root节点。
中序遍历中在root节点之前的元素，为root节点的左子树，在root之后的即为右子树。
步骤：
1. 先从先序遍历找到root节点
2. 在中序遍历中找到root节点，左侧为左子树，右侧为右子树
3. 将先序遍历和中序遍历分别拆为两个数组，递归调用函数

注意计算左右子树的size；
左子树的size = i，即为在中序遍历中，root的index
右子树的size = count - i - 1，即总个数减去左子树的个数，再减去根节点。



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

/*
先序遍历的首元素，即为二叉树的root节点。
中序遍历中在root节点之前的元素，为root节点的左子树，在root之后的即为右子树。
步骤：
1. 先从先序遍历找到root节点
2. 在中序遍历中找到root节点，左侧为左子树，右侧为右子树
3. 将先序遍历和中序遍历分别拆为两个数组，递归调用函数
*/

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){

    if (preorderSize == 0) return NULL;
    
    // 申请空间
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    // 获取到根节点
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;

    // 遍历中序数组，找到根节点
    int i = 0;
    while (root->val != inorder[i++]){}
    // 退回一位
    i--;


    // 左子树
    // 下一个先序遍历数组
    int *next_preorder_left = preorder + 1;
    // 下一个中序遍历数组
    int *next_inorder_left = inorder;
    // 数组个数都为i
    root->left = buildTree(next_preorder_left,i, next_inorder_left, i);

    // 右子树
    int *next_preorder_right = preorder + i + 1;
    int *next_inorder_right = inorder + i + 1;
    // 右子树个数
    int right_count = preorderSize - i - 1;
    root->right = buildTree(preorder+1+i, right_count, next_inorder_right, right_count);

    return root;
}
```