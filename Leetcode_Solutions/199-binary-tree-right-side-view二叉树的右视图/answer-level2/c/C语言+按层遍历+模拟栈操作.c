### 解题思路
采用分层遍历二叉树的思想，利用栈保存一层中的所有节点，每层的最后一个节点为右视时看到的该层的值。
利用数组加双指针来模拟栈操作。
依次出栈即从左到右遍历了该层的每个节点
遍历上一层时，将每个节点的左右子树（如果有）压如栈中，保存下一层的节点。
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
#define RET_SIZE 500

int* rightSideView(struct TreeNode* root, int* returnSize){
    int *ret = (int*)malloc(sizeof(int) * RET_SIZE);
    int retSize = 0;
    struct TreeNode* stack[RET_SIZE];
    int front = -1;
    int top = -1;

    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    stack[0] = root;
    front = 0;
    top = 0;
    int nextLevel = 0;
    int curCount = 1;

    while (top - front > -1) {
        struct TreeNode* pNode = stack[front];
        if (pNode->left != NULL) {
            stack[++top] = pNode->left;
            ++nextLevel;
        }
        if (pNode->right != NULL) {
            stack[++top] = pNode->right;
            ++nextLevel;
        }
        ++front;
        --curCount;
        if (curCount == 0) {
            ret[retSize++] = pNode->val;
            curCount = nextLevel;
            nextLevel = 0;
        }
    }

    *returnSize = retSize;
    return ret;
}

```