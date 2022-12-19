定义基本的队列操作，根据树的节点数动态创建队列；
前序遍历，使节点入队；
暂存并队列中的目标数据序列地址，释放队列结构本身；
返回目标数据序列的地址即可
```
typedef struct {
    int* data;
    int rear;
    int size;
} MyQueue;

MyQueue* MyQueueCreate(int k) {
    MyQueue* obj = (MyQueue*)calloc(1, sizeof(MyQueue));
    if (obj == NULL) {
        return NULL;
    }

    obj->data = (int*)calloc(k, sizeof(int));
    if (obj->data == NULL) {
        free(obj);
        return NULL;
    }

    obj->size = k;
    obj->rear = -1;

    return obj;
}

bool MyQueueEnQueue(MyQueue* obj, int value) {
    if (obj->rear >= (obj->size - 1)) {
        return false;
    }

    int pos = obj->rear + 1;
    obj->data[pos] = value;
    obj->rear = pos;

    return true;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getBiTreeNodeNum(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftNodeNum = getBiTreeNodeNum(root->left);
    int rightNodeNum = getBiTreeNodeNum(root->right);

    return 1 + leftNodeNum + rightNodeNum;
}

void preorderEnQueue(struct TreeNode* root, MyQueue* obj)
{
    if (root != NULL) {
        MyQueueEnQueue(obj, root->val);
        preorderEnQueue(root->left, obj);
        preorderEnQueue(root->right, obj);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int nodeNum = getBiTreeNodeNum(root);

    MyQueue* obj = MyQueueCreate(nodeNum);
    if (obj == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // 前序入队
    preorderEnQueue(root, obj);

    // 暂存目标数据，释放队列结构
    int* nums = obj->data;
    free(obj);

    *returnSize = nodeNum;

    return nums;
}
```
