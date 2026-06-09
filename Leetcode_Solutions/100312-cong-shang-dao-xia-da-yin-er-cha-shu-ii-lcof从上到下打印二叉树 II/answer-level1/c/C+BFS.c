1、把访问的顶点存到队列中
2、从队列中取出节点，访问该节点的左右孩子节点，把访问的的节点存入队列中
3、重复2过程

```
#define MAX_TREE_QUEUE_NUM 0xffff

typedef struct TreeNode TreeNode;
TreeNode g_queue[MAX_TREE_QUEUE_NUM];
 
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    int front = 0;
    int rear = 0;
    int numOfEveryLayer = 0;
    int **result = NULL;

    TreeNode nowTree;
    TreeNode *tempTree1;
    TreeNode *tempTree2;

    *returnSize = 0;

    if (root == NULL) {
        return NULL;
    }
    (*returnColumnSizes) = (int *)malloc(MAX_TREE_QUEUE_NUM * sizeof(int));
    result = (int **)malloc(MAX_TREE_QUEUE_NUM * sizeof(int *));

    nowTree = *root;
    result[*returnSize] = (int *)malloc(1 * sizeof(int));
    result[*returnSize][numOfEveryLayer++] = nowTree.val;
    (*returnColumnSizes)[*returnSize] = numOfEveryLayer;
    g_queue[rear++] = nowTree;

    while (front < rear) {
        numOfEveryLayer = 0;
        result[++(*returnSize)] = (int *)malloc(512 * sizeof(int));
        //前一层节点的个数
        for (int i = 0; i < (*returnColumnSizes)[(*returnSize) - 1]; i++) {
            nowTree = g_queue[front++];

            tempTree1 = nowTree.left;
            tempTree2 = nowTree.right;

            if (tempTree1 != NULL) {
                result[*returnSize][numOfEveryLayer++] = tempTree1->val;
                g_queue[rear++] = *tempTree1;
            }
            if (tempTree2 != NULL) {
                result[*returnSize][numOfEveryLayer++] = tempTree2->val;
                g_queue[rear++] = *tempTree2;
            }
        }

        (*returnColumnSizes)[*returnSize] = numOfEveryLayer;
    }

    return result;
}
```
