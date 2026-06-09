### 解题思路
储存结果用的内存所用的内存是最小的。

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
#define MAX_CAPACITY 1000
typedef struct queue
{
    int front;
    int rear;
    int size;
    struct TreeNode elem[MAX_CAPACITY];
} queue;
void initial_queue(queue *s)
{
    s->size = 0;
    s->front = 0;
    s->rear = 0;
    for (int i = 0; i < MAX_CAPACITY; i++)
    {
        s->elem[i].val = 0;
        s->elem[i].left = NULL;
        s->elem[i].right = NULL;
    }
}
void in_Queue(queue *s, struct TreeNode node)
{
    if (s->size == MAX_CAPACITY)
        return;
    s->elem[s->rear++] = node;
    s->rear %= MAX_CAPACITY;
    s->size++;
}
void out_Queue(queue *s, struct TreeNode *node)
{
    if (s->size == 0)
        return;
    *node = s->elem[s->front++];
    s->front %= MAX_CAPACITY;
    s->size--;
}
int isEmpty(queue s)
{
    if (s.size == 0)
        return 1;
    else
        return 0;
}

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    if (root == NULL)
    {
        *returnSize = 0;
        return (int **)NULL;
    }

    int **Tree_Array = (int **)malloc(sizeof(int *));
    Tree_Array[0] = (int *)malloc(sizeof(int));
    *returnColumnSizes = (int *)malloc(sizeof(int));
    queue aux_queue;
    struct TreeNode temp;
    int level_wide = 1;
    int next_level_wide = 0;
    int depth = 1;
    (*returnColumnSizes)[depth - 1] = 1;

    initial_queue(&aux_queue);
    in_Queue(&aux_queue, *root);
    while (!isEmpty(aux_queue))
    {
        out_Queue(&aux_queue, &temp);

        if (temp.left != NULL)
        {
            in_Queue(&aux_queue, *temp.left);
            next_level_wide++;
        }
        if (temp.right != NULL)
        {
            in_Queue(&aux_queue, *temp.right);
            next_level_wide++;
        }

        Tree_Array[depth - 1][(*returnColumnSizes)[depth - 1] - level_wide] = temp.val;

        if (--level_wide == 0)
        {
            level_wide = next_level_wide;
            next_level_wide = 0;
            Tree_Array = (int **)realloc(Tree_Array, sizeof(int *) * ++depth);
            Tree_Array[depth - 1] = (int *)malloc(sizeof(int) * level_wide);
            *returnColumnSizes = (int *)realloc(*returnColumnSizes, sizeof(int) * depth);
            (*returnColumnSizes)[depth - 1] = level_wide;
        }
    }
    *returnSize = depth - 1;
    return Tree_Array;
}
```