```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000000
/*
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int **res;
int *col;
int rescnt;
void Process(struct TreeNode **nodes, int *visited, int size, int *prev, int psize)
{
    int cnt = 0;
    int new = false;
    for (int i = 0; i < size; i++) {
        if (visited[i] == 0) {
            new = true;
            visited[i] = 1;
            prev[psize] = nodes[i]->val;
            if (nodes[i]->left != NULL) {
                nodes[size + cnt] = nodes[i]->left;
                cnt++;
            }
            if (nodes[i]->right != NULL) {
                nodes[size + cnt] = nodes[i]->right;
                cnt++;
            }
            Process(nodes, visited, size + cnt, prev, psize + 1);
            visited[i] = 0;
            cnt = 0;
        }
    }

    if (new == false) {
        /*
         * for (int i = 0; i < size; i++) {
         *     printf("%d ", prev[i]);
         * }
         * printf("\n");
         */
        res[rescnt] = malloc(sizeof(int) * size);
        col[rescnt] = size;
        memcpy(res[rescnt++], prev, sizeof(int) * size);
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** BSTSequences(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    struct TreeNode **nodes = malloc(sizeof(struct TreeNode *) * MAX);
    memset(nodes, 0, sizeof(struct TreeNode *) * MAX);

    int *visited = malloc(sizeof(int) * MAX);
    memset(visited, 0, sizeof(int) * MAX);
    int *prev = malloc(sizeof(int) * MAX);
    memset(prev, 0, sizeof(int) * MAX);
    col = malloc(sizeof(int) * MAX);
    memset(col, 0, sizeof(int) * MAX);
    res = malloc(sizeof(int *) * MAX);
    memset(res, 0, sizeof(int *) * MAX);

    rescnt = 0;
    nodes[0] = root;
    if (root != NULL) {
        Process(nodes, visited, 1, prev, 0);
    } else {
        rescnt = 1;
    }
    *returnColumnSizes = col;
    *returnSize = rescnt;
    return res;
}

```
