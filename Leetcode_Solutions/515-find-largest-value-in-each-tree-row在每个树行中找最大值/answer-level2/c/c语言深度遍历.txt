思路：
1) 申请一个用于保存每一层最大值的数组，数组元素初始化为INT_MIN；    
2) 深度遍历每一个节点，对于每个节点，将节点的值与节点所在层（level）当前的最大值比较，如果大于该层当前的最大值，则更新该层最大值；
3) 深度遍历的同时返回树的深度；

代码：
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAXLEVE     1000
#define MAX(a, b)   ((a) > (b) ? (a) : (b))

int TreeWalk(struct TreeNode *node, int level, int *max) {
    int leftDepth = 0, rightDepth = 0;

    if (node == NULL) {
        return 0;
    }
    if (node->val > max[level]) {
        max[level] = node->val;
    }

    if (node->left != NULL) {
        leftDepth = TreeWalk(node->left, level + 1, max);
    }
    if (node->right != NULL) {
        rightDepth = TreeWalk(node->right, level + 1, max);
    }

    return MAX(leftDepth, rightDepth) + 1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize){
    int *max = NULL;
    int depth = 0;
    int i;

    *returnSize = 0;

    if (root == NULL) {
        return NULL;
    }

    max = (int *)malloc(sizeof(int) * MAXLEVE);
    for (i = 0; i < MAXLEVE; i++) {
        max[i] = INT_MIN;
    }

    depth = TreeWalk(root, 0, max);
    *returnSize = depth;

    return max;
}