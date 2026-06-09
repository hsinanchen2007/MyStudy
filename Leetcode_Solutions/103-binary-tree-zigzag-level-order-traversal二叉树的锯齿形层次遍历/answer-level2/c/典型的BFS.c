### 解题思路
典型的BFS

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

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL) {
        (* returnSize) = 0;
        return NULL;
    }
    int **result = (int**)malloc(sizeof(int*) * 1000);
    for (int i = 0; i < 1000; ++i) {
        result[i] = malloc(sizeof(int) * 1000);
        memset(result[i], 0, sizeof(int) * 1000);
    }
    (*returnColumnSizes) = malloc(sizeof(int*) * 1000);
    memset(((*returnColumnSizes)), 0, sizeof(int*) * 1000);
    struct TreeNode* visit[1000] = {0};
    visit[0] = root;
    int visitSize = 1;
    int layer = 0;
    while (visitSize != 0) {
        (* returnSize)= layer + 1;
        (*returnColumnSizes)[layer] = visitSize;
        struct TreeNode* queue[1000] = {0};
        int queueSize = 0;
        for (int i = 0; i < visitSize; ++i) {
            // 锯齿状保持本层的结果
            if (layer % 2 == 0) {
                result[layer][i] = visit[i]->val;
            } else {
                result[layer][visitSize - i - 1] = visit[i]->val;
            }
            //下一层的指针，放到queue里面
            if (visit[i]->left != NULL) {
                queue[queueSize] = visit[i]->left;
                queueSize++;
            }
            if (visit[i]->right != NULL) {
                queue[queueSize] = visit[i]->right;
                queueSize++;
            }
        }
        memset(visit, 0, sizeof(struct TreeNode*) * visitSize);
        memcpy(visit, queue, sizeof(struct TreeNode*) * queueSize);
        layer++;
        visitSize = queueSize;
    }
    return result;
}
```