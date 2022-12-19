```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAXSIZE 2000
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int*)*MAXSIZE);
    *returnColumnSizes = (int*)malloc(sizeof(int)*MAXSIZE);

    int nums[MAXSIZE] = {0};
    struct TreeNode * Queue[MAXSIZE];

    int front = 0;
    int rear = 0;
    int last = 0;
    int level = 0;

    int numsCnt = 0;
    int levelCnt = 0;

    if(root == NULL) {
        *returnSize = 0;
        return res;
    }

    Queue[rear++] = root;
    last = rear;
    while(front < rear) {
        //节点依次出队        
        struct TreeNode *p = Queue[front++];        
        nums[levelCnt++] = p->val;
        //下一次节点依次入队
        if(p->left) {
            Queue[rear++] = p->left;
        }
        if(p->right) {
            Queue[rear++] = p->right;
        }
        //当是本层最后一个节点时，记录到结果中
        if (front == last) {
            last = rear;
            (*returnColumnSizes)[level] = levelCnt;
            res[level] = (int*)malloc(sizeof(int)*levelCnt);
            for(int i = 0; i < levelCnt; i++) {                
                res[level][i] = nums[i];
            }
            level++;//总层数加1
            memset(nums, 0, sizeof(int)*MAXSIZE);

            levelCnt = 0;//本层节点数清零
        }
    }
    *returnSize = level;
    return res;
}
```
