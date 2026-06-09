### 解题思路
N叉树， BFS

### 代码

```c
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_NODE_SIZE 10000
#define MAX_DEPTH_SIZE 1000

int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL) {
        
        (*returnColumnSizes) = (int*)calloc(1, sizeof(int));
        (*returnColumnSizes)[0] = 0;
        return NULL;
    } 
    int depth = 0;
    int front = 0;
    int rear = 0;
   

    (*returnColumnSizes) = (int*)calloc(MAX_NODE_SIZE, sizeof(int));
    struct Node* g_treeNode[MAX_NODE_SIZE];
    int** result = (int**)malloc(sizeof(int*) * MAX_DEPTH_SIZE);
    result[*returnSize] = (int *)malloc(1 * sizeof(int));
    result[(*returnSize)][depth] = root->val;
    (*returnColumnSizes)[*returnSize] = depth + 1;
    g_treeNode[rear++] = root;

    while (front < rear) {
        depth = 0;
        result[++(*returnSize)] = (int*)calloc(5000, sizeof(int));

        for (int i = 0; i < (*returnColumnSizes)[(*returnSize) - 1]; i++) {
            root = g_treeNode[front++];
            for (int j = 0; j < root->numChildren; j++) {
                result[*returnSize][depth++] = root->children[j]->val;
                g_treeNode[rear++] = root->children[j];
            }
            
        }
        (*returnColumnSizes)[*returnSize] = depth;
    }  
    return result;  
}
```