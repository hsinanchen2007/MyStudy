```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


#define MAX(a, b)   ((a) > (b) ? (a) : (b))

int* largestValues(struct TreeNode* root, int* returnSize){

    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int head = 0;
    int tail;
    int last;
    int max = INT_MIN;
    int level = 0;
    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 10000);
    int *retArr = (int *)malloc(sizeof(int) * 1000);

    *returnSize = 0;

    queue[0] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    queue[0] = root;
    tail++;

    while (head < tail) {
        last = tail;
        while (head < last) {
            max = MAX(max, queue[head]->val);

            if (queue[head]->left != NULL) {
                queue[tail] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                queue[tail] = queue[head]->left;
                tail++;
            }
            
            if (queue[head]->right != NULL) {
                queue[tail] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                queue[tail] = queue[head]->right;
                tail++;     
            }

            head++;
        }
        retArr[level] = max;
        level++;
        max = INT_MIN;
    }

    *returnSize = level;
    return retArr;
}
```
