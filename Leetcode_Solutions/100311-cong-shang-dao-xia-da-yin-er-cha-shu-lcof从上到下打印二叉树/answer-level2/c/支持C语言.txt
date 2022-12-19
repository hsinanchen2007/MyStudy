### 解题思路
循环队列+BFS

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
#define MAXSIZE 1009

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

int* levelOrder(struct TreeNode* root, int* returnSize){
    int* nums = malloc(sizeof(int) * MAXSIZE);
    int i = 0, j;
    
    if(root != NULL){
        SeqQueue* Q = createSeqQueue();
        EnQueue(Q, root);

        while(!QueueEmpty(Q)){
            struct TreeNode* temp = DeQueue(Q);
            nums[i++] = temp->val;
            if(temp->left != NULL)
                EnQueue(Q, temp->left);
            if(temp->right != NULL)
                EnQueue(Q, temp->right);
        }
    }

    //printf("%d\n", i);
    *returnSize = i;
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