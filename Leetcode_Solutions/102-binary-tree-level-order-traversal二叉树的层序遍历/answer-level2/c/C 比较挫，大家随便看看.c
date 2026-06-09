/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 typedef struct Node{
    struct TreeNode *val;
    int depth;
    struct Node *next;
 }Node;

typedef struct Queue{
    Node *top;
    Node *end;
    int count;
}Queue;

void InitQueue(Queue *queue)
{
    queue = (Queue *)malloc(sizeof(Queue));
    queue->top = NULL;
    queue->end = NULL;
    queue->count = 0;
}

void InQueue(struct TreeNode *val, int depth, Queue *queue) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->depth = depth;
    if(queue->count == 0) {
        queue->top = newNode;
        queue->end = newNode;
    } else {
        queue->end->next = newNode;
        queue->end = newNode;
    }
    queue->count++;
}

Node * OutQueue(Queue *queue)
{
    if (queue->count == 0) {
        return 0;
    }
    Node *tmpNode = NULL;
    tmpNode = queue->top;
    queue->top = queue->top->next;
    queue->count--;
    return tmpNode;
}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    Queue *queue = NULL;
    queue = (Queue *)malloc(sizeof(Queue));
    queue->top = NULL;
    queue->end = NULL;
    queue->count = 0;
    int depth = 0;
    if (root != NULL) {
        depth++;
        InQueue(root, depth, queue);
    }
    int temparray[10000] = {0};
    int count = 0;
    int columecount = 0;
    int columnsize[10000] = {0};
    while(queue->count != 0) {
        Node * tempNode = OutQueue(queue);
        struct TreeNode *temp = tempNode->val;
        temparray[count++] = temp->val;
        if(depth != tempNode->depth){
            depth++;
            columecount++;
            columnsize[columecount]++;
        } else{
            columnsize[columecount]++;
        }
        if (temp->left != NULL) {
            InQueue(temp->left,tempNode->depth+1 , queue);
        } 
        if (temp->right != NULL){
            InQueue(temp->right,tempNode->depth+1 , queue);
        }
    }

    int **result = (int **)malloc(sizeof(int *) * depth);
    *returnColumnSizes = (int *)malloc(sizeof(int) * depth);
    int countone = 0;
    for(int i=0;i<depth;i++){ 
        result[i] = (int *)malloc(sizeof(int) * columnsize[i]);
        for (int j=0;j<columnsize[i];j++){
            result[i][j] = temparray[countone++];
             
        }
        (*returnColumnSizes)[i] = columnsize[i];
    }
    *returnSize = depth;
    return result;
}

