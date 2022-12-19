### 解题思路
BFS，使用队列模拟递归，此处仅做C代码展示，有很多包括书写习惯需要改正的地方，待修改

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

#define STACKSIZE 10000
typedef struct stackNode{
    int path;
    struct TreeNode* treeNode;
};

bool hasPathSum(struct TreeNode* root, int sum){
    if(root == NULL) return false;

    struct stackNode *stack[STACKSIZE], *node, *p;
    node = (struct stackNode*)malloc(sizeof(struct stackNode));
    int top = -1, bottom = -1;
    node -> path = sum - root -> val;
    node -> treeNode = root;

    stack[++top] = node;

    while(top != bottom){
        p = stack[++bottom];
        if(p -> treeNode -> left == NULL && p -> treeNode -> right == NULL && p -> path == 0) return true;
        
        if(p -> treeNode -> left != NULL) {
            struct stackNode *lnode = (struct stackNode*)malloc(sizeof(struct stackNode));
            lnode -> path = p -> path - p -> treeNode -> left -> val;
            lnode -> treeNode = p -> treeNode -> left;
            stack[++top] = lnode;
        }
        if(p -> treeNode -> right != NULL) {
            struct stackNode *rnode = (struct stackNode*)malloc(sizeof(struct stackNode));
            rnode -> path = p -> path - p -> treeNode -> right -> val;
            rnode -> treeNode = p -> treeNode -> right;
            stack[++top] = rnode;
        }
    }
    return false;
}


```