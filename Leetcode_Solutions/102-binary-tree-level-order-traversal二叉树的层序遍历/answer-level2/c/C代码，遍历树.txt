/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct QNode{
    struct TreeNode* data;    
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct Que{
    QueuePtr front;
    QueuePtr rear;
    int count;
}LinkQue;

void InitQue(LinkQue *Q)
{
    Q->front = (QueuePtr) malloc(sizeof(QNode));
    Q->rear = Q->front;
    Q->front->data = NULL;
    Q->front->next = NULL;
    Q->count = 0;
    return;    
}

void DestroyQue(LinkQue *Q)
{
    while(Q->front != NULL)
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;        
    }
    return;
}

void EnQue(LinkQue *Q, struct TreeNode* data)
{
    QNode *pNewNode = malloc(sizeof(QNode));
    
    pNewNode->data = data;
    pNewNode->next = NULL;
    
    Q->rear->next = pNewNode;
    Q->rear = pNewNode;    
    
    (Q->count)++;
    return;
}

void DeQue(LinkQue *Q, struct TreeNode** data)
{
    QNode *pTempNode = NULL;
        
    if (Q->front == Q->rear)
    {
        return ;
    }
    
    pTempNode = Q->front->next;
    *data = pTempNode->data;
    
    Q->front->next = pTempNode->next;
    
    if (Q->rear == pTempNode)
    {
        Q->rear = Q->front;
    }
    
    free(pTempNode);
    
    (Q->count)--;
    
    return;
}

int QueEmpty(LinkQue *Q)
{
    if (Q->front == Q->rear)
    {
        return 1;
    }
    
    return 0;
}

int QueSize(LinkQue *Q)
{
    return Q->count;
}

/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int max = 2000;     
    int col = 0;
    int level = 0;
    int coltemp = 0;
    struct TreeNode  *popnode = NULL;    
    LinkQue Que = {0};    
    int size = 0;
    int **res = (int **)malloc(max * sizeof(int *));    
    int *retcol = (int *)malloc(max * sizeof(int));    
        
    InitQue(&Que);
    
    if (root == NULL)
    {
        *returnSize = level;
        return res;
    }
    
    /* root */
    EnQue(&Que, root);
    
    /* 插入分隔符 */
    EnQue(&Que, NULL);
    
    retcol[0] = 1;
   
    while(QueEmpty(&Que) == 0)
    {        
        col = QueSize(&Que) - 1; /* 去掉分隔符 */
        if (col == 0)
        {
            break;
        }    
                
        DeQue(&Que, &popnode);
                
        if (popnode == NULL) /* 间隔符 */
        {            
            coltemp = 0;
            level++;           
            
            res[level] = (int *)malloc(col * sizeof(int));  
            retcol[level] = col;
            
            /* 插入分隔符 */
            EnQue(&Que, NULL);     
                                    
            continue;
        }                
        
        if (level == 0)
        {
            res[level] = (int *)malloc(col * sizeof(int));       
            retcol[level] = col;
        }        
                
        res[level][coltemp] = popnode->val;
                                            
        coltemp++;            
                
        if (popnode->left == NULL && popnode->right == NULL)
        {
            continue;
        }        
        
        if (popnode->left != NULL)
        {
            EnQue(&Que, popnode->left);
        }
        
        if (popnode->right != NULL)
        {
            EnQue(&Que, popnode->right);
        }                     
    }
        
    *returnSize = level + 1;
    *returnColumnSizes = retcol;
                  
    DestroyQue(&Que);   
      
    return res;
}