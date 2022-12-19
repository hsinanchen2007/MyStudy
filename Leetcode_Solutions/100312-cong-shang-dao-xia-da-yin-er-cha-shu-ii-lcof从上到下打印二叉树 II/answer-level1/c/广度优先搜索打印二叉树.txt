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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if(root == NULL){
        return NULL;
    }
    struct TreeNode* q[1000]; // 队列
    int head = 0, tail = 0; // head指向队首元素，tail指向队尾元素之后的空位

    q[tail++] = root;

    int array[1000][500]; // 暂存打印的二叉树节点值，设置1000的目的是预防极限情形：1000个节点一对一连接
    int colSize[1000]; // 暂存每一个level的节点个数
    int p1 = 0; // array[p2][p1]和colSize[p2]
    int p2 = 0;

    int currNum = 1; // 暂存当前level的节点个数
    int nextNum = 0; // 暂存下一个level的节点个数

    colSize[p2++] = currNum;
    while(head != tail){
        if(currNum == 0){
            currNum = nextNum;
            nextNum = 0;
            colSize[p2++] = currNum;
            p1 = 0;
        }
        struct TreeNode* node = q[head++];
        head %= 1000;
        currNum--;

        array[p2 - 1][p1++] = node->val;

        if(node->left != NULL){
            q[tail++] = node->left;
            tail %= 1000;
            nextNum++;
        }

        if(node->right != NULL){
            q[tail++] = node->right;
            tail %= 1000;
            nextNum++;
        }       
    }
    *returnSize = p2;
    *returnColumnSizes = (int*)malloc(p2 * sizeof(int));
    memcpy(*returnColumnSizes, colSize, p2 * sizeof(int));

    int** result = (int**)malloc(p2 * sizeof(int*));
    for(int i = 0; i < p2; ++i){
        result[i] = (int*)malloc(colSize[i] * sizeof(int));
        memcpy(result[i], array[i], colSize[i] * sizeof(int));
    }
    return result;
}
```
