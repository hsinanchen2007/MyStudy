### 解题思路
遇到这种“找符合某条件的路径”、“是否存在否和某条件的路径”的问题，我首先想到的是使用广度优先搜索。
整体思路：“一级一级的入队，一个一个的出队。弹出叶子判条件，不是叶子儿入队。”
入队的节点怎么定义：该题要找的是符合目标值的路径，入队的每个节点应包含：节点信息（便于找它的子节点）、剩余目标值（用于判断是否符合目标值要求。）
条件判断：叶子节点，剩余目标值与此叶子节点的值相等，则表示存在满足条件的路径。
队列相关操作：初始化、入队、出队、队列是否为空、销毁队列。这些函数其他编程语言中都有库函数可以直接调用，然鹅，C没有，自己实现吧。实现一个相对通用的方法，下次遇到类似的问题，还可以复用。

整体流程如下：
   1、需要一个队列，用来存储要检查的节点。队列中的每个节点保存树节点和剩余的目标和。
   2、root节点的子节点先入队，剩余目标和分别减去root节点的值。
   3、队列中弹出一个节点：
      （1）如果弹出的是叶子节点，检查剩余目标和与该节点的值是否相等。相等，则说明存在目标值相同的路径。否则继续执行3.
      （2）如果弹出的不是叶子节点，将它的子节点入队，并更新子节点的剩余目标值 = 当前弹出节点的剩余目标值 - 当前弹出节点的值。继续执行3.
      （3）如果没有节点可弹出了，说明队列为空，没有满足目标值的路径了。

### 代码

```c

/**************************通用队列实现：以下**************************/
typedef struct tagQUEUE_NODE_S{
    struct tagQUEUE_NODE_S *priv;
    struct tagQUEUE_NODE_S *next;
    void *data;   
}QUEUE_NODE_S;

/* 
    使用循环双向链表实现队列
    retval: 返回一个节点的地址，其中它的next为队列头，priv为队列尾
*/
QUEUE_NODE_S *queue_init(void) {
    QUEUE_NODE_S *node = (QUEUE_NODE_S *)malloc(sizeof(QUEUE_NODE_S));
    if (node == NULL) {
        return NULL;
    }

    node->next = node;
    node->priv = node;
    node->data = NULL;
    return node;
}

/*
    description： 首尾相等，则队列为空。
    param：
        node：队列指针
    attention： 调用者保证指针不为空
*/
bool queue_is_empty(QUEUE_NODE_S *node) {
    if (node->next == node->priv && node->next == node) {
        return true;
    }

    return false;
}

/*
    description： 数据从队列尾入队
    param：
        node：队列指针
        data：需要入队的数据
    attention： 调用者保证指针不为空
*/
void queue_in(QUEUE_NODE_S *node, void *data) {
    QUEUE_NODE_S *newNode = (QUEUE_NODE_S *)malloc(sizeof(QUEUE_NODE_S));
    if (newNode == NULL) {
        return;
    }
    newNode->data = data;
    newNode->next = node;
    newNode->priv = node->priv;
    node->priv->next = newNode;
    node->priv = newNode;

    return;
}
/*
    description： 数据从队列首出队
    param：
        node：队列指针
    retval：出队的数据,
    attention： 调用者释放返回的data
*/
void *queue_out(QUEUE_NODE_S *node)
{
    QUEUE_NODE_S *outNode = node->next;
    outNode->next->priv = node;
    node->next = outNode->next;

    void *data = outNode->data;
    free(outNode);

    return data;
}

/* 销毁队列 */
void queue_destroy(QUEUE_NODE_S *node)
{
    QUEUE_NODE_S *curNode = node;
    QUEUE_NODE_S *nextNode = node->next;

    while (curNode != NULL) {
        if (curNode->data != NULL) {
            free(curNode->data);
            curNode->data = NULL;
        }
        /* 先摘链，再释放 */
        if (curNode->next == curNode->priv && curNode->next == curNode) {
            free(curNode);
            curNode = NULL;
        } else {
            nextNode = curNode->next;
            curNode->next->priv = curNode->priv;
            curNode->priv->next = curNode->next;
            free(curNode);
            curNode = nextNode;
        }
    }
    return;
}
/**************************通用队列实现：以上**************************/

/* 
   使用广度优先搜索：
   1、需要一个队列，用来存储要检查的节点。队列中的每个节点保存树节点和剩余的目标和。
   2、root节点的子节点先入队，剩余目标和分别减去root节点的值。
   3、队列中弹出一个节点：
      （1）如果弹出的是叶子节点，检查剩余目标和与该节点的值是否相等。相等，则说明存在目标值相同的路径。否则继续执行3.
      （2）如果弹出的不是叶子节点，将它的子节点入队，并更新子节点的剩余目标值 = 当前弹出节点的剩余目标值 - 当前弹出节点的值。继续执行3.
      （3）如果没有节点可弹出了，说明队列为空，没有满足目标值的路径了。
*/
/*
 * struct TreeNode {
 *    int val;
 *    struct TreeNode *left;
 *    struct TreeNode *right;
 * };
 */

typedef struct tagQUEUE_DATA_S {
    struct TreeNode *node;
    int leftVal;
}QUEUE_DATA_S;

#define EOK 0
#define ERR 1

int TreeNodeQueueIn(QUEUE_NODE_S *queueHead, struct TreeNode* node, int fatherValue, int leftvalue)
{
    QUEUE_DATA_S *data = (QUEUE_NODE_S *)malloc(sizeof(QUEUE_DATA_S));
    if (data == NULL) {
        return ERR;
    }
    data->node = node;  
    data->leftVal = leftvalue - fatherValue;
    queue_in(queueHead, (void *)data);

    return EOK;
}



bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) {
        return false;
    }
    /*1、需要一个队列，用来存储要检查的节点。队列中的每个节点保存树节点和剩余的目标和。*/
    QUEUE_NODE_S *queueHead = queue_init();
    if (queueHead == NULL) {
        return false;
    }

    int ret = TreeNodeQueueIn(queueHead, root, 0, sum);
    if (ret != EOK) {
        queue_destroy(queueHead);
        return false;
    }

    while(!queue_is_empty(queueHead)) {
        QUEUE_DATA_S *queueData = (QUEUE_DATA_S *)queue_out(queueHead);
        if (queueData == NULL) {
            queue_destroy(queueHead);
            return false;
        } 

        struct TreeNode *treeNode = queueData->node;
        /* 已经是叶子节点 */
        if (treeNode->left == NULL && treeNode->right == NULL) {
            if (treeNode->val == queueData->leftVal) {
                free(queueData);
                queueData = NULL;
                queue_destroy(queueHead);
                return true;
            }
            else {
                continue;
            }       
        }

        if (treeNode->left != NULL) {
            (void)TreeNodeQueueIn(queueHead, treeNode->left, treeNode->val, queueData->leftVal);
        }

        if (treeNode->right != NULL) {
            (void)TreeNodeQueueIn(queueHead, treeNode->right, treeNode->val, queueData->leftVal);  
        }

        free(queueData);
        queueData = NULL;
    }

    queue_destroy(queueHead);
    return false;
}


```

### 引申
该题目还可以要求输出符合条件的路径。可以在队列的每个节点保存已经经过的路径（包含当前节点），则最后一个弹出的叶子节点中保存的路径，就是完整路径。

```c
int TreeNodeQueueIn(QUEUE_NODE_S *queueHead, struct TreeNode* node, int *pastVal, int cnt, int fatherValue, int leftvalue)
{
    if (leftvalue <= fatherValue) {
        return ERR;
    }

    QUEUE_DATA_S *data = (QUEUE_DATA_S *)malloc(sizeof(QUEUE_DATA_S));
    if (data == NULL) {
        return ERR;
    }
    data->node = node;  
    data->leftVal = leftvalue - fatherValue;

    int pos = 0;
    data->pastVal = (int *)malloc(sizeof(int) * (cnt + 1));
    if (data->pastVal == NULL) {
        free(data);
        return ERR;
    }
    if (pastVal != NULL) {
        memcpy(data->pastVal, pastVal, cnt * sizeof(int));
        pos = cnt;
    }
    data->pastVal[pos] = data->node->val;
    data->cnt = cnt + 1;

    queue_in(queueHead, (void *)data);

    return EOK;
}

void printPath(int *pastVal, int cnt) {
    int i;
    for (i = 0; i < cnt; i++) {
        printf("%d ", pastVal[i]);
    }
    return;
}

bool hasPathSum(struct TreeNode* root, int sum){
    /*1、需要一个队列，用来存储要检查的节点。队列中的每个节点保存树节点和剩余的目标和。*/
    QUEUE_NODE_S *queueHead = queue_init();
    if (queueHead == NULL) {
        return false;
    }

    int ret = TreeNodeQueueIn(queueHead, root, NULL, 0, 0, sum);
    if (ret != EOK) {
        queue_destroy(queueHead);
        return false;
    }

    while(!queue_is_empty(queueHead)) {
        QUEUE_DATA_S *queueData = (QUEUE_DATA_S *)queue_out(queueHead);
        if (queueData == NULL) {
            queue_destroy(queueHead);
            return false;
        } 

        struct TreeNode *treeNode = queueData->node;
        /* 已经是叶子节点 */
        if (treeNode->left == NULL && treeNode->right == NULL) {
            if (treeNode->val == queueData->leftVal) {
                printPath(queueData->pastVal, queueData->cnt);
                free(queueData->pastVal);
                queueData->pastVal = NULL;
                free(queueData);
                queueData = NULL;
                queue_destroy(queueHead);
                return true;
            }
            else {
                continue;
            }
        }
        if (treeNode->left != NULL) {
            ret = TreeNodeQueueIn(queueHead, treeNode->left, queueData->pastVal, queueData->cnt, treeNode->val, queueData->leftVal);
        }

        if (treeNode->right != NULL) {
            ret = TreeNodeQueueIn(queueHead, treeNode->right, queueData->pastVal, queueData->cnt, treeNode->val, queueData->leftVal);
        }
        free(queueData->pastVal);
        queueData->pastVal = NULL;
        free(queueData);
        queueData = NULL;
    }

    queue_destroy(queueHead);
    return false;
}

```
