### 解题思路
此处撰写解题思路

（1）中序遍历时相等结点的下一个元素就是所求的元素；
（2）注意：入参指针需要制定为二维指针，flag也需要制定为一维指针的形式，当找到元素的时候需要将flag置为0，否则会被后边的元素冲掉。

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
void myInorderSuccessor(struct TreeNode* root, struct TreeNode* p, struct TreeNode **res, int *flag)
{
    if (root == NULL) {
        return;
    }

    myInorderSuccessor(root->left, p, res, flag); 
    if (*flag == 1) {
        *res = root;
        *flag = 0;
        return;
    }
    if (root == p && *flag == 0) {
        *flag = 1;
    }

    myInorderSuccessor(root->right, p, res, flag);
}

struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p){
    struct TreeNode *res = NULL;
    int flag = 0;
    if (root == NULL || p == NULL) {
        return NULL;
    }

    myInorderSuccessor(root, p, &res, &flag);
    return res;
}

```