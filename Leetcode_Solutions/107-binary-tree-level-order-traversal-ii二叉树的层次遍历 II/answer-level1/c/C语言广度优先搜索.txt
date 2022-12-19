### 解题思路
正常的广度优先搜索思路，用一个树节点数组作为队列进行层次遍历，需要注意的是输出需要倒着输出

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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void BFS(int **ret, struct TreeNode **queue, int start, int end, int* returnSize, int** returnColumnSizes)
{
    int qLen = end - start;
    int i;
    int startFlag = start;
    int endFlag = end;
    // 如果队列长度为0说明没有节点了，直接返回
    if (qLen <= 0) {
        return;
    }
    // 为该层节点申请内存，并赋值
    ret[(*returnSize)] = (int *)malloc(sizeof(int) * qLen);
    for (i = 0; i < qLen; i++) {
        ret[(*returnSize)][i] = queue[start + i]->val;
    }
    (*returnColumnSizes)[(*returnSize)] = qLen;
    (*returnSize)++;
    // 将队列中节点的子节点入队，并将该层节点出队
    for (i = startFlag; i < endFlag; i++) {
        if (queue[i]->left != NULL) {
            queue[end++] = queue[i]->left;
        }
        if (queue[i]->right != NULL) {
            queue[end++] = queue[i]->right;
        }
        start++;
    }
    // 继续广度优先搜索
    BFS(ret, queue, start, end, returnSize, returnColumnSizes);
    return;
}
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    // 如果节点为空直接返回，但是要注意returnSize要置为0
    *returnSize = 0;
    if (root == NULL) {
        * returnSize = 0;
        return NULL;
    }
    // 为返回值申请内存
    int **ret = (int **)malloc(sizeof(int *) * 2000);
    // 为队列申请内存
    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 2000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 2000);
    memset(queue, 0, sizeof(int) * 2000);
    // 将根节点入队
    queue[0] = root;
    // 代表队列出口的start设为0，入口end设为1，
    int start = 0;
    int end = 1;
    // 广度优先搜索
    BFS(ret, queue, start, end, returnSize, returnColumnSizes);
    // 遍历完将ret原地转换顺序，注意returnColumnSizes也要换
    int i;
    int *temp = NULL;
    int tempNum;
    for (i = 0; i < (*returnSize) / 2; i++) {
        temp = ret[i];
        tempNum = (*returnColumnSizes)[i];
        ret[i] = ret[(*returnSize) - i - 1];
        ret[(*returnSize) - i - 1] = temp;
        (*returnColumnSizes)[i] = (*returnColumnSizes)[(*returnSize) - i - 1];
        (*returnColumnSizes)[(*returnSize) - i - 1] = tempNum;
    }
    return ret;
}
```