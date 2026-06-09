
![image.png](https://pic.leetcode-cn.com/334a74748b316552c8ee6a061984bb0d2583c46bd573e61bb25c0020bbaa1595-image.png)

动态根据树的节点数创建队列；
中序遍历入队；
对队列的升序特性进行校验；

需要注意的点是用例中存在正负LONG_MAX的边界值，所以校验升序特性的最大值变量要初始化为 -LONG_MAX，这一点挺恶心的。

```
typedef struct {
    int* data;
    int size;
    int rear;
} MyQueue;

MyQueue* myQueueCreate(int k) {
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

bool myQueueEnQueue(MyQueue* obj, int value) {
    if (obj->rear >= (obj->size - 1)) {
        return false;
    }

    int pos = obj->rear + 1;
    obj->data[pos] = value;
    obj->rear = pos;

    return true;
}

void myQueueFree(MyQueue* obj) {
    free(obj->data);
    free(obj);
}

int getBiTreeNodeNum(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftNodeNum = getBiTreeNodeNum(root->left);
    int rightNodeNum = getBiTreeNodeNum(root->right);

    return 1 + leftNodeNum + rightNodeNum;
}

void inorderEnQueue(struct TreeNode* root, MyQueue* obj)
{
    if (root != NULL) {
        inorderEnQueue(root->left, obj);
        myQueueEnQueue(obj, root->val);
        inorderEnQueue(root->right, obj);
    }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValidBST(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }

    if (root->left == NULL && root->right == NULL) {
        return true;
    }

    int nodeNum = getBiTreeNodeNum(root);

    MyQueue* obj = myQueueCreate(nodeNum);
    if (obj == NULL) {
        return true;
    }

    inorderEnQueue(root, obj);

    int i;
    long maxVal = -LONG_MAX;
    for (i = 0; i < nodeNum; i++) {
        if (maxVal >= obj->data[i]) {
            myQueueFree(obj);
            return false;
        }
        maxVal = obj->data[i];
    }

    myQueueFree(obj);
    return true;
}
```



