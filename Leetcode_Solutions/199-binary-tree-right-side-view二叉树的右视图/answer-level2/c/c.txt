### 解题思路
此处撰写解题思路

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

void Bfs(struct TreeNode* node, int *ret, int *returnSize)
{
    struct TreeNode* que[100] = {0};
    int front = 0;
    int rear = 0;
    que[rear++] = node;
    while (front != rear) {
        struct TreeNode* temp = que[front];
		ret[*returnSize] = temp->val;
        *returnSize += 1;
        int num = rear - front;
		while (num != 0) {
            num--;
            temp = que[front++];
            if (temp->right != NULL) {
                que[rear++] = temp->right;
            }
			if (temp->left != NULL) {
                que[rear++] = temp->left;
            }
        } 
    }
}

int* rightSideView(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    int *ret = (int*)malloc(sizeof(int) * 100);
    Bfs(root, ret, returnSize);
    return ret;
}
```