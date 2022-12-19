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
    if (root == NULL) {
        return NULL;
    }
    int qSize = 5; // initial size of queue
    struct TreeNode** q = (struct TreeNode**)malloc(qSize * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail] = root;
    
    int countOfNodeOfcurrentLevel = 1; // 保存当前level的节点数
    int countOfNodeOfNextLevel = 0; // 保存下一个level的节点数
    
    int** output = NULL;
    
    int p = -1; // 在往output中添加元素时充当index
    
    while (head <= tail) {
        if (p == -1) { // 新的level开始
            if (*returnSize == 0) { // 第一次进入while循环时
                *returnSize = 1;
                output = (int**)malloc((*returnSize) * sizeof(int*));
                *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));               
            }
            else { 
                (*returnSize) += 1;
                output = (int**)realloc(output, (*returnSize) * sizeof(int*));
                *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*returnSize) * sizeof(int));
            }
            output[*returnSize - 1] = (int*)malloc(countOfNodeOfcurrentLevel * sizeof(int));
            (*returnColumnSizes)[*returnSize - 1] = countOfNodeOfcurrentLevel;
        }

        struct TreeNode* node = q[head++]; // pop出队顶node
        countOfNodeOfcurrentLevel--; // 当前level的节点个数-1
        output[*returnSize - 1][++p] = node->val; // 将当前节点的val加入output
        
        if (node->left != NULL) { 
            if (tail == qSize - 1) { // 当队列的内存不够
                q = (struct TreeNode**)realloc(q, (qSize += 5) * sizeof(struct TreeNode*));
            }   
            q[++tail] = node->left; // 将当前node的left child入队
            countOfNodeOfNextLevel++; // 下一level的节点数+1
        }
        
        if (node->right != NULL) {
            if (tail == qSize - 1) {
                q = (struct TreeNode**)realloc(q, (qSize += 5) * sizeof(struct TreeNode*));
            }  
            q[++tail] = node->right;
            countOfNodeOfNextLevel++;
        }
        
        if (countOfNodeOfcurrentLevel == 0) { // 当前level节点数==0
            countOfNodeOfcurrentLevel = countOfNodeOfNextLevel; // 将下一层节点数赋予当前节点数，在下次while循环时开启下一个level的遍历
            countOfNodeOfNextLevel = 0;
            p = -1;
        }
    }
    free(q);
    q = NULL;
    return output;
}
```
