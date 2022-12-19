
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int num = 0;
void dfsNum(struct TreeNode* node, int sum, int calcSum)
{
    if (node == NULL) {
        return;
    }
    calcSum += node->val;

    if (calcSum == sum) {
        num++;
    }

    dfsNum(node->left, sum, calcSum);
    dfsNum(node->right, sum, calcSum);
}

void dfsNode(struct TreeNode* node, int sum, int calcSum)
{
    if (node == NULL) {
        return;
    }

    calcSum = 0; // 每个节点开始都初始化为0
    dfsNum(node, sum, calcSum);

    dfsNode(node->left, sum, calcSum);
    dfsNode(node->right, sum, calcSum);

    return;
}

int pathSum(struct TreeNode* root, int sum){
    int calcSum = 0;

    if (root == NULL) {
        return 0;
    }

    num = 0;
    dfsNode(root, sum, calcSum);

    return num;
}