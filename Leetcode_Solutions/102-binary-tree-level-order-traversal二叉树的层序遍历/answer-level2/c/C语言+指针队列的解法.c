
![image.png](https://pic.leetcode-cn.com/089d8fac8368c549261cbaa8750f9f87da79f5c889bcdf0fcf46f10a95f031cb-image.png)

新建一个树节点地址的队列，实现基本的入队操作；
无需出队，而是新增一个队列遍历 myQueueTraver 操作；
算法的基本步骤如下：
1. 根节点入队，初始化相关变量；
2. 按树的深度迭代
   2.1 按当前层的节点个数迭代
    每遍历一个当前层的节点（移动下标cur即可），就加入该节点的左右子节点到队列
   2.2 此层新增的节点数为下一层需迭代的次数

```
typedef struct {
    struct TreeNode** data;
    int size;
    int rear;
    int cur;
} MyQueue;

MyQueue* myQueueCreate(int k) {
    MyQueue* obj = (MyQueue*)calloc(1, sizeof(MyQueue));
    if (obj == NULL) {
        return NULL;
    }

    obj->data = (struct TreeNode**)calloc(k, sizeof(struct TreeNode*));
    if (obj->data == NULL) {
        free(obj);
        return NULL;
    }

    obj->size = k;
    obj->rear = -1;
    obj->cur = -1;

    return obj;
}

bool myQueueEnQueue(MyQueue* obj, struct TreeNode *treeNode) {
    if (obj->rear >= (obj->size - 1)) {
        return false;
    }

    if (treeNode == NULL) {
        return true;
    }

    int pos = obj->rear + 1;
    obj->data[pos] = treeNode;
    obj->rear = pos;

    return true;
}

struct TreeNode * myQueueTraver(MyQueue* obj) {
    if (obj->rear < 0) {
        return NULL;
    }
    obj->cur += 1;

    return obj->data[obj->cur];
}

void myQueueFree(MyQueue* obj) {
    free(obj->data);
    free(obj);
}

int getBiTreeDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = getBiTreeDepth(root->left);
    int rightDepth = getBiTreeDepth(root->right);

    return 1 + (leftDepth >= rightDepth ? leftDepth : rightDepth);
}

int getBiTreeNodeNum(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftNodeNum = getBiTreeNodeNum(root->left);
    int rightNodeNum = getBiTreeNodeNum(root->right);

    return 1 + leftNodeNum + rightNodeNum;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL || returnSize == NULL || returnColumnSizes == NULL) {
        *returnSize = 0;
        returnColumnSizes = NULL;
        return NULL;
    }

    int i, j;
    int depthNum = getBiTreeDepth(root);
    int** returnNumsArray = (int**)calloc(depthNum, sizeof(int*));
    int* columnSizes = (int*)calloc(depthNum, sizeof(int));

    // 申请队列用于保存树节点的地址
    int nodeNum = getBiTreeNodeNum(root);
    MyQueue* obj = myQueueCreate(nodeNum);
    if (obj == NULL) {
        *returnSize = 0;
        returnColumnSizes = NULL;
        return NULL;
    }

    // 根节点入列，初始化相关变量
    myQueueEnQueue(obj, root);
    int cuLevelNodeNum = 1;
    columnSizes[0] = 1;
    int rearLast = 0;

    struct TreeNode* curNode = NULL;
    for (i = 0; i < depthNum; i++) {
        // 保存输出当前深度(层)的节点数
        columnSizes[i] = cuLevelNodeNum;
        returnNumsArray[i] = (int*)calloc(cuLevelNodeNum, sizeof(int));
        //printf("i=%d, cuLevelNodeNum=%d\n", i, cuLevelNodeNum);

        // 当前层有几个节点，就要进行几轮节点出队和节点的子节点入队的操作
        for (j = 0; j < cuLevelNodeNum; j++) {
            // 获得要出队（实际未出队，而是遍历节点）的节点，保存其值用于返回输出
            curNode = myQueueTraver(obj);
            returnNumsArray[i][j] = curNode->val;

            if (curNode->left != NULL) {
                myQueueEnQueue(obj, curNode->left);
                //printf("j=%d, left, obj->rear=%d\n", j, obj->rear);
            }
            if (curNode->right != NULL) {
                myQueueEnQueue(obj, curNode->right);
                //printf("j=%d, right, obj->rear=%d\n", j, obj->rear);
            }
        }

        // 此轮入队的节点数，即该层的节点数
        cuLevelNodeNum = obj->rear - rearLast;
        rearLast = obj->rear;
    }

    *returnSize = depthNum;
    *returnColumnSizes = columnSizes;
    myQueueFree(obj);
    return returnNumsArray;
}
```



