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
#define MAX_LEN 1000
void queryNode(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q, struct TreeNode *nodeList[3][MAX_LEN], int deep) {
    int i = 0;

    if (root == NULL) {
        return;
    }

    nodeList[0][deep] = root;

    if (root == p){
        for (i = 0; i <= deep; i++) {
            nodeList[1][i] = nodeList[0][i];
        }
    }
    if (root == q){
        for (i = 0; i <= deep; i++) {
            nodeList[2][i] = nodeList[0][i];
        }
    }

    queryNode(root->left, p, q, nodeList, (deep+1));
    queryNode(root->right, p, q, nodeList, (deep+1));

    return;
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *nodeList[3][MAX_LEN];
    int i = 0;
    
    //遍历循环，找出p、q所在的路径，把这两个路径分别存入nodeList[1]、nodeList[2]
    queryNode(root, p, q, nodeList, 0);

    //比较数组nodeList[1]、nodeList[2]
    while (nodeList[1][i] == nodeList[2][i]) {
        i++;
    }

    return nodeList[1][i-1];
}
```