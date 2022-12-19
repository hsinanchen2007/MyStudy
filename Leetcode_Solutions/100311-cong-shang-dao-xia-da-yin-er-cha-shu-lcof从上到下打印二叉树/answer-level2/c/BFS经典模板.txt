### 解题思路
BFS经典模板

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
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 2000
#define TREE_MAX_SIZE 5000
int* levelOrder(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    int* ret = (int*)calloc(MAX_SIZE, sizeof(int));

    struct TreeNode** treeNode = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * TREE_MAX_SIZE);
    int rear = 0;
    int front = 0;
    
    treeNode[rear++] = root;
    ret[(*returnSize)++] = root->val;

    while (front < rear) {
        int len = rear - front;

        for (int i = 0; i < len; i++) {
            struct TreeNode* temp = treeNode[front++];
            if (temp->left) {
                treeNode[rear++] = temp->left;
                ret[(*returnSize)++] = temp->left->val;
            }
            if (temp->right) {
                treeNode[rear++] = temp->right;
                ret[(*returnSize)++] = temp->right->val;
            }
        }

    }
    return ret;
}
```