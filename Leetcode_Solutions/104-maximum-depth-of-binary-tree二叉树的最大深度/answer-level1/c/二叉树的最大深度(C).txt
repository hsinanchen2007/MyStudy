### 解题思路
层次遍历，常规题。还是用STL吧，自己写队列太浪费时间了。

### 代码

```c

typedef struct TreeNode* NodePtr;
typedef struct tagNode{
    NodePtr val;
    struct tagNode* next;
}QueueNode;
typedef struct{
    QueueNode* front;
    QueueNode* rear;
}Queue;

void enQueue(Queue* q, NodePtr t)
{
    QueueNode* p = (QueueNode*)malloc(sizeof(QueueNode));
    q->rear->next = p;
    q->rear = p;
    q->rear->val = t;
    q->rear->next = NULL;
}

struct QueueNode* deQueue(Queue* q)
{
    if(q->front == q->rear)
        exit(0);
    if(q->front->next == q->rear){
        NodePtr tmp = q->rear->val;
        free(q->rear);
        q->rear = q->front;
        q->front->next = NULL;
        return tmp;
    }
    QueueNode* del = q->front->next;
    NodePtr tmp = del->val;
    q->front->next = del->next;
    free(del);
    del = NULL;
    return tmp;
}

int maxDepth(struct TreeNode* root){
    if(!root)
        return 0;

    /*init queue*/
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = (QueueNode*)malloc(sizeof(QueueNode));
    q->front->next = NULL;

    enQueue(q, root);

    int depth = 0;
    NodePtr p, lastNode = root, newLastNode = NULL;
    while(q->front != q->rear){
        p = deQueue(q);
        if(p->left){
            enQueue(q, p->left);
            newLastNode = p->left;
        }
        if(p->right){
            enQueue(q, p->right);
            newLastNode = p->right;
        }
        if(p == lastNode){
            depth++;
            lastNode = newLastNode;
        }
    }
    return depth;
}
```