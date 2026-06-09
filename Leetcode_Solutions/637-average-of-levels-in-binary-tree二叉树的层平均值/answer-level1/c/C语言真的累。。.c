### 解题思路
利用循环队列进行层次遍历

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
#define MAXSIZE 1000

typedef struct{
    struct TreeNode** data;
    int front;
    int rear;
}SeqQueue;

SeqQueue* createSeqQueue();
int QueueLength(SeqQueue* obj);
bool QueueEmpty(SeqQueue* obj);
bool QueueFull(SeqQueue* obj);
void EnQueue(SeqQueue* obj, struct TreeNode* node);
struct TreeNode* DeQueue(SeqQueue* obj);
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes);

double* averageOfLevels(struct TreeNode* root, int* returnSize){
    int* returnColumnSizes;
    int** nums = levelOrder(root, returnSize, &returnColumnSizes);
    double* arr = malloc(sizeof(double) * (*returnSize));
    int i, j;
    long int sum;

    for(i=0; i<*returnSize; i++){
        sum = 0;

        for(j=0; j<returnColumnSizes[i]; j++)
            sum += (long int)nums[i][j];
        
        arr[i] = (double)sum/(returnColumnSizes[i]);
    }

    return arr;
}

//层序遍历，返回二维数组
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** nums = malloc(sizeof(int *) * MAXSIZE); //定义二维数组存储节点值
    int* sizes = malloc(sizeof(int) * MAXSIZE);  //定义一维数组存储每一层节点个数
    int i, j, k;
    for(i=0; i<MAXSIZE; i++)
        nums[i] = (int *)malloc(sizeof(int) * MAXSIZE);
    
    i = -1; //层号
    if(root != NULL){
        SeqQueue* Q = createSeqQueue();
        EnQueue(Q, root);

        while(!QueueEmpty(Q)){
            //记录树的深度，即层树
            i++;

            //保存第i层全部节点的个数
            sizes[i] = QueueLength(Q);

            //保存第i层全部节点
            for(j=0; j<sizes[i]; j++){ //列号
                k = (Q->front+j)%MAXSIZE; //队列号
                nums[i][j] = Q->data[k]->val;
            }

            //打印每一层节点
            //QueuePrint(Q);
            
            //弹出第i层全部节点，并存入下一层全部节点值
            k = Q->rear; //保存第i层树节点在队列中的队尾号
            struct TreeNode* temp; //临时节点用于保存从队列弹出的节点
            while(Q->front != k){
                temp = Q->data[Q->front];
                DeQueue(Q); //弹出

                if(temp->left != NULL)
                    EnQueue(Q, temp->left); //存入左孩子
                
                if(temp->right != NULL)
                    EnQueue(Q, temp->right); //存入右孩子
            }
        }
    }

    *returnSize = i+1; //二叉树的深度，即层数
    int* columnSizes = malloc(sizeof(int) * (*returnSize));
    for(i=0; i<*returnSize; i++)
        columnSizes[i] = sizes[i];
    *returnColumnSizes = columnSizes;
    
    return nums;
}

//定义循环队列并初始化
SeqQueue* createSeqQueue(){
    SeqQueue* obj;
    obj = (SeqQueue *)malloc(sizeof(SeqQueue));
    obj->data = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAXSIZE);
    obj->front = 0;
    obj->rear = 0;
    return obj;
}

//队列长度
int QueueLength(SeqQueue* obj){
    return (obj->rear - obj->front + MAXSIZE)%MAXSIZE;
}

//队列是否为空
bool QueueEmpty(SeqQueue* obj){
    return obj->front == obj->rear;
}

//队列是否为满
bool QueueFull(SeqQueue* obj){
    return (obj->rear+1)%MAXSIZE == obj->front;
}

//入队
void EnQueue(SeqQueue* obj, struct TreeNode* node){
    if( (obj->rear+1)%MAXSIZE != obj->front ){
        obj->data[obj->rear] = node;
        obj->rear = (obj->rear+1)%MAXSIZE;
    }
}

//出队
struct TreeNode* DeQueue(SeqQueue* obj){
    if(obj->front != obj->rear){
        int k = obj->front;
        obj->front = (obj->front+1)%MAXSIZE;
        return obj->data[k];
    }
    return NULL;
}

```