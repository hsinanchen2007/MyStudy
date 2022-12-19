![image.png](https://pic.leetcode-cn.com/a65152794a78954af4676a32d4340f355c0fa2a89e1c809071687db0e7531fb2-image.png)

### 解题思路
先序遍历：根-左-右。一路到左子节点为空，返回向右访问。是为深度优先搜索。

递归：
问题简化：当前节点为*空*，则返回空；非空时，先记录其*节点值*，然后访问*左子树*，再访问*右子树*。
函数A（currNode）->A(currNode->left)->A(currNode->right)
然后打磨细节
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
int treeSize(struct TreeNode* root){
    if(!root) return 0;     
    return treeSize(root->left) + treeSize(root->right) + 1;
}
void preOrder(struct TreeNode* root, int *res, int *i){
    if(root){
        (*i)++;
        res[*i] = root->val;
        preOrder(root->left, res, i);
        preOrder(root->right, res, i);     
    }
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int size = treeSize(root);
    if(!root || size == 0){
        *returnSize = 0;
        return NULL;
    } 
    int *res = (int *)malloc(sizeof(int) * size);
    int i = -1;
    preOrder(root, res, &i);//i的传递，从0或者-1开始，可以试一下，经常从-1开始效果很好
    *returnSize = size;
    return res;
}


```