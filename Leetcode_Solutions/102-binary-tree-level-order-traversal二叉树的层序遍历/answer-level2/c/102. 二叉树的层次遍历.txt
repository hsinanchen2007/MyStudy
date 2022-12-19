### 解题思路
1、递归遍历二叉树
2、将结果逐层放入堆栈
3、然后将结果再转移到表格里输出
![image.png](https://pic.leetcode-cn.com/a03fe56cd2dd053da534afe0d918aa35f5b1defadafaf51ceadc0eca608a5883-image.png)

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

 typedef struct _node_t {
     int val;
     struct _node_t *next;
 } node_t;

int maxDepth(struct TreeNode* root){
    if (root == NULL) return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return (left > right ? left : right) + 1;
}
void OrderTree(struct TreeNode* root, int* returnSize, int** returnColumnSizes, node_t *table, int level)
{
    if (root == NULL) return;

    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->val = root->val;
    node->next = table[level].next;
    table[level].next = node;

    (*returnColumnSizes)[level]++;

    OrderTree(root->right, returnSize, returnColumnSizes, table, level + 1);
    OrderTree(root->left , returnSize, returnColumnSizes, table, level + 1);
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL || returnSize == NULL || returnColumnSizes == NULL) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = maxDepth(root);
    *returnColumnSizes = (int *)malloc(sizeof(int *) * (*returnSize));
    int **ret = (int **)malloc(sizeof(int **) * (*returnSize));
    node_t *table = (node_t *)malloc(sizeof(node_t) * (*returnSize));

    for (int i=0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 0;
        table[i].next = NULL;
    }

    OrderTree(root , returnSize, returnColumnSizes, table, 0);

    for (int i=0; i < (*returnSize); i++) {
        ret[i] = (int *)malloc(sizeof(int) * (*returnColumnSizes)[i]);
        node_t *pos = table[i].next;
        for (int j=0; pos != NULL; j++, pos = pos->next) {
            ret[i][j] = pos->val;
        }
    }
    free(table);

    return ret;
}

/* test case

[3,9,20,null,null,15,7]

[]

*/

```