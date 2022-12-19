### 解题思路
在循环队列进行层次遍历的基础上，在队列结构里增加一项数组，用于保存二叉树节点所在位置。

C语言真的是要被时代淘汰了吗？写着好累好累

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
#define MAX(a,b) ((a>b) ? a : b)
#define MAXSIZE 1000

typedef struct{
    struct TreeNode** data;
    unsigned long int pos[MAXSIZE];
    int front;
    int rear;
}SeqQueue;

SeqQueue* createSeqQueue();
int QueueLength(SeqQueue* obj);
bool QueueEmpty(SeqQueue* obj);
bool QueueFull(SeqQueue* obj);
void EnQueue(SeqQueue* obj, struct TreeNode* node, unsigned long int position);
struct TreeNode* DeQueue(SeqQueue* obj);
void QueuePrint(SeqQueue* obj);

int widthOfBinaryTree(struct TreeNode* root){
    int i=0, j, k, width=0, left, right;

    if(root != NULL){
        SeqQueue* Q = createSeqQueue();
        EnQueue(Q, root, 1);
        width = 1;

        while(!QueueEmpty(Q)){
            i++;
            k = Q->rear;
            struct TreeNode* temp;
            unsigned long int proot;
        
            while(Q->front != k){
                temp = Q->data[Q->front];
                proot = Q->pos[Q->front];
                DeQueue(Q);

                if(temp->left != NULL)
                    EnQueue(Q, temp->left, 2*proot);
                
                if(temp->right != NULL)
                    EnQueue(Q, temp->right, 2*proot+1);
            }

            if(!QueueEmpty(Q)){
                left = Q->pos[Q->front];
                right = Q->pos[(Q->rear==0) ? (MAXSIZE-1) : (Q->rear-1)];
                width = MAX(width, right - left + 1);
                //QueuePrint(Q);
                //printf("%d\n", width);
            }
        }
    }

    return width;
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
void EnQueue(SeqQueue* obj, struct TreeNode* node, unsigned long int position){
    if( (obj->rear+1)%MAXSIZE != obj->front ){
        obj->data[obj->rear] = node;
        obj->pos[obj->rear] = position;
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

//队列遍历
void QueuePrint(SeqQueue* obj){
    int i, k;
    for(i=0; i<QueueLength(obj); i++){
        k = (obj->front+i)%MAXSIZE;
        printf("[%d:%d] ", obj->pos[k], obj->data[k]->val);
    }
    printf("\n");
}

```