### 解题思路
通用的BFS，一个队列再用奇偶反转赋值即可。熟悉套路，知道这几个参数应该如何复制就很简单。

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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define QUE_NUMS 10000
static struct TreeNode* g_que[QUE_NUMS];

// void Push(int *head,node)
// {
//     g_que[*head] = node->left;
//     *head = (*head + 1) % QUE_NUMS;
// }

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }
    int** storeArr = (int**)malloc(sizeof(int*) * QUE_NUMS);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * QUE_NUMS);
    int head = 0, tail = 0;

    g_que[head] = root;
    head = (head + 1) % QUE_NUMS;

    int idx = 0;
    while(head != tail){
        int size = (head - tail + QUE_NUMS) % QUE_NUMS;//获取队列大小，遍历队列。
        storeArr[idx] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[idx] = size;
        for(int i = 0; i < size;++i){ //  
            struct TreeNode* node = g_que[tail];
            tail = (tail + 1) % QUE_NUMS;
            if((idx % 2) ==0){
                storeArr[idx][i] = node->val;
            }else {
                storeArr[idx][size - 1 - i] = node->val;
            }
            // printf("%d ",node->val);
            if(node->left){
                g_que[head] = node->left;
                head = (head + 1) % QUE_NUMS;
            }
            if(node->right){
                g_que[head] = node->right;
                head = (head + 1) % QUE_NUMS;
            }
            
        }
        idx++;
        // printf("\n");
    }
    *returnSize = idx;
    // printf("*returnSize: %d\n",*returnSize);

    return storeArr;
}






```