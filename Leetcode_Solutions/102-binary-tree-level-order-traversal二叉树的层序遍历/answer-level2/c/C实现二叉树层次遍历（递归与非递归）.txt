### 解题思路
1.递归法
```c
int depth(struct TreeNode *root)
{
    int ld=0,rd=0;
    if(root)
	{
        ld=depth(root->left)+1;
        rd=depth(root->right)+1;  
    }
    return ld>=rd?ld:rd;
}

void level_order_recursion(struct TreeNode *root,int **array,int * ColumnSizes,int level)
{
    if(root == NULL)
        return;

    if(array[level] == NULL)
    {
       //array[level] = (int*)malloc(sizeof(int) * pow(2,level));不为何在最后一个调用时没有通过
        array[level] = (int*)malloc(sizeof(int) * 200);
    }
    array[level][ColumnSizes[level]++] = root->val;

    if(root->left)
    {
        level_order_recursion(root->left,array,ColumnSizes,level+1);
    }
    if(root->right)
    {
        level_order_recursion(root->right,array,ColumnSizes,level+1);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderRecursion(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    int **array = NULL;

    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = depth(root);
    array = (int**)malloc(sizeof(int*) * (*returnSize));
    if(array == NULL)
    {
        printf("failed malloc for array!\n");
        return NULL;
    }
        

    memset((void*)array,0,sizeof(int*) * (*returnSize));

    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    if(*returnColumnSizes == NULL)
    {
        printf("failed malloc csize\n");
        return NULL;
    }

    memset((void*)*returnColumnSizes,0,sizeof(int) * (*returnSize));
    
    level_order_recursion(root,array,*returnColumnSizes,0);
    return array;
}
```
2.非递归，采用一个队列，在遍历每层的节点时使其子节点入队
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
typedef struct
{
    struct TreeNode **array;
    int head;
    int tail;
    int length;
    int len;//记录当前队列的长度
}MyQueue;

//输入为队列可用长度
MyQueue *queue_create(int length)
{
    MyQueue *queue = (MyQueue*)malloc(sizeof(MyQueue));
    if(queue == NULL)
        return NULL;
    queue->array = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*(length+1));
    if(queue->array == NULL)
        return NULL;
    queue->head = 0;
    queue->tail = 0;
    queue->length = length + 1;
    queue->len = 0;
    return queue;
}

int enqueue(MyQueue *q,struct TreeNode *node)
{
    if(q == NULL || q->array == NULL || (q->tail+1) % q->length == q->head || node == NULL)
        return -1;
    q->array[q->tail++ % q->length] = node;
    q->len++;
    return 0;
}

struct TreeNode *dequeue(MyQueue *q)
{
    if(q == NULL || q->array == NULL || q->len == 0)
        return NULL;
    q->len--;
    return q->array[q->head++ % q->length]; 
}

int depth(struct TreeNode *root)
{
    int ld=0,rd=0;
    if(root)
	{
        ld=depth(root->left)+1;
        rd=depth(root->right)+1;  
    }
    return ld>=rd?ld:rd;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    int **array = NULL;
    MyQueue *q = NULL;
    int level = 0;
    int level_length;//每层长度
    struct TreeNode *node = NULL;
    int i;

    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = depth(root);
    array = (int**)malloc(sizeof(int*) * (*returnSize));
    if(array == NULL)
        return NULL;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    if(*returnColumnSizes == NULL)
        return NULL;
    memset((void*)*returnColumnSizes,0,sizeof(int) * (*returnSize));

    q = queue_create(1000);
    if(q == NULL)
        return NULL;

    enqueue(q,root);
    while(q->head != q->tail)
    {
        level_length = q->len;
        array[level] = (int*)malloc(sizeof(int)*level_length);
        //函数失败在此就不写了

        for(i=0;i<level_length;i++)
        {
            node = dequeue(q);
            array[level][returnColumnSizes[0][level]++] = node->val;
            if(node->left)
                enqueue(q,node->left);
            if(node->right)
                enqueue(q,node->right);
        } 
        level++;  
    }

    return array;   
}
```