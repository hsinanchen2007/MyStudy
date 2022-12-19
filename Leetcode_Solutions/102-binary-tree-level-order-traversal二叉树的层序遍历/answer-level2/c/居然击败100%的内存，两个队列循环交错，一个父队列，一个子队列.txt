

struct TreeLinkList{
    struct TreeNode * val;
    struct TreeLinkList * next;
    struct TreeLinkList *pre;
};
typedef struct TreeLinkList * P_TreeLinkList;

typedef struct {
    P_TreeLinkList header;
    P_TreeLinkList tail;
    int count;
}TreeQueue;

typedef TreeQueue * P_TreeQueue;

P_TreeQueue createTreeQueue() {
    P_TreeQueue treeQ = (P_TreeQueue)malloc(sizeof(TreeQueue));
    if (treeQ == NULL) {
        return NULL;
    }
    memset(treeQ, 0, sizeof(TreeQueue));
    treeQ->header = NULL;
    treeQ->tail = NULL;
    return treeQ;
}
void push(P_TreeQueue q, struct TreeNode * p) {
    P_TreeLinkList pList = (P_TreeLinkList)malloc(sizeof(struct TreeLinkList));
    if (pList == NULL) {
        return NULL;
    }
    memset(pList, 0, sizeof(struct TreeLinkList));

    pList->val = p;
    pList->next = NULL;

    if (q->header == NULL) {
        q->header = pList;
        q->tail = pList;
    }
    else {
        q->tail->next = pList;
        q->tail = q->tail->next;
    }
    q->count++;
}

P_TreeLinkList front(P_TreeQueue q) {
    if (q && q->header) {
        //printf("front val = %d\n", q->header->val->val);
        P_TreeLinkList ret = q->header;
        q->header = q->header->next;
        q->count--;
        return ret;
    }
    else {
        return NULL;
    }
}

int getTreeHeight(struct TreeNode * node) {
    if (node == NULL) {
        return 0;
    }
    int hr;
    int hl;
    int max;
    hr = getTreeHeight(node->right);
    hl = getTreeHeight(node->left);
    max = hr > hl ? hr : hl;
    return (max + 1);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    P_TreeQueue pTreeQueue = createTreeQueue();
    P_TreeQueue cTreeQueue = createTreeQueue();
    int height = getTreeHeight(root);
    *returnSize = height;
    int *columnsSizes =  (int *) malloc(sizeof(int) * height);
    memset(columnsSizes, 0 , sizeof(int) * height);
    int **result =  (int **) malloc(sizeof(int*) * height);
    push(pTreeQueue, root);
    int level = 0;
    while (pTreeQueue && pTreeQueue->count)
    {
        //printf("level=%d\n", level);
        int *levelItems =  (int *) malloc(sizeof(int) * pTreeQueue->count);
        //printf("level1\n");
        memset(levelItems, 0 , sizeof(int) * pTreeQueue->count);
        //printf("level2\n");
        //printf("tree height=%d\n", height);
        columnsSizes[level] = pTreeQueue->count;
        //printf("before while\n");

        P_TreeLinkList f = NULL;

        int count = 0;
        while ( f = front(pTreeQueue) ) {
            //printf("val = %d\n", f->val->val);
            levelItems[count] = f->val->val;
            count++;
            if (f->val->left) {
                //printf("val left = %d\n", f->val->left->val);
                push(cTreeQueue, f->val->left);
            }
            if (f->val->right) {
                //printf("val right = %d\n", f->val->right->val);
                push(cTreeQueue, f->val->right);
            }
            //printf("val = %d\n", f->val->val);
            free(f);
            f = NULL;
        }

        result[level] = levelItems;
        level++;
        if (cTreeQueue->count > 0) {
            free(pTreeQueue);
            
            pTreeQueue = NULL;
            pTreeQueue = cTreeQueue;
            cTreeQueue = NULL;
            
            //printf("count = %d\n", pTreeQueue->count);
            cTreeQueue = createTreeQueue();
            //printf("count = %d\n", pTreeQueue->count);
        }
        else {
            if (cTreeQueue) {
                free(cTreeQueue);
                cTreeQueue = NULL;
            }
            if (pTreeQueue) {
                free(pTreeQueue);
                pTreeQueue = NULL;
            }
        }
    }
    *returnColumnSizes = columnsSizes;
    return result;
}