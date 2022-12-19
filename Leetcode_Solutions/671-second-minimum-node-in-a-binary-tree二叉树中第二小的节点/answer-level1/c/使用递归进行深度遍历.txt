使用递归进行深度遍历，将最小值和第二小的值作为入参并通过指针带出来，在遍历过程中判断当前节点的值：
如果当前值比最小的大，比第二小的小，则更新第二小的值；如果当前值比最小的小，那么将最小值更新为第二小的值，将当前值设置为最小值。
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void findSecMinProcess(int *minFirst, int *minSecond, struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    if ((root->val > *minFirst) && ((root->val < *minSecond) || (*minSecond == -1))) {
        *minSecond = root->val;
    } else if ((root->val < *minFirst)) {
        *minSecond = *minFirst;
        *minFirst = root->val;
    }
 
    findSecMinProcess(minFirst, minSecond, root->left);  
    findSecMinProcess(minFirst, minSecond, root->right);
}

int findSecondMinimumValue(struct TreeNode* root){
    int minFirst = -1;
    int minSecond = -1;
    
    if (root == NULL) {
        return -1;
    }
    
    minFirst = root->val;
    findSecMinProcess(&minFirst, &minSecond, root->left);
    findSecMinProcess(&minFirst, &minSecond, root->right);
    
    return minSecond;
}
```
