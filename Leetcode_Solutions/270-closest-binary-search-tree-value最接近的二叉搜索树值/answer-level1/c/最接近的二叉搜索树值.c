### 解题思路
遍历某一分支直至该节点为NULL，保存迄今为止差值最小的节点的值。

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

int closestValue(struct TreeNode* root, double target){
    if (root == NULL) {
        return -1;
    }
    double minCha = 0xffffffff;
    int curNum = root->val;
    int minNum = root->val;
    double curCha = 0;
    struct TreeNode* curNode = root;
    while (true) {
        if (curNode == NULL) {
            return minNum;
        }
        curNum = curNode->val;
        if (curNum < target) {
            curCha = target - curNum;
            curNode = curNode->right;
        }else{
            curCha = curNum - target;
            curNode = curNode->left;
        }
        if (curCha < minCha) {
            minNum = curNum;
            minCha = curCha;
        }
    }
    return minNum;
}
```