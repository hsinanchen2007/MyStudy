
直接复制来的，这样的成绩好像确实优秀了一些

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
int result;

int BSTSubtree(struct TreeNode* root, int* p_minVal, int* p_maxVal) {
    if (root == NULL) {
        printf("递归结束点1：本节点为空！\n");
        return 0;
    }
    if ( (root->left == NULL) && (root->right == NULL) ) {
        *p_minVal = root->val;
        *p_maxVal = root->val;
        printf("min = %d, max = %d\n", *p_minVal, *p_maxVal);
        printf("递归结束点2：叶子节点！\n");
        return 1;
    }
    //左子树最小值和最大值
    int lmin;
    int lmax;
    //右子树最小值和最大值
    int rmin;
    int rmax;
    //左子树为BST时的节点个数 -1表示非BST
    int ln = BSTSubtree(root->left, &lmin, &lmax);
    //右子树为BST时的节点个数 -1表示非BST
    int rn = BSTSubtree(root->right, &rmin, &rmax);
    if (ln == -1 || rn == -1) {
        return -1;
    }
    //根节点 小于左子树的最大值 或 大于右子树的最小值 不是BST
    if ((ln != 0 && root->val <= lmax) || (rn != 0 && root->val >= rmin)) {
        return -1;
    }
    
    // 该树为BST n为树节点总数
    // 左/右子树非空且是BST 
    *p_minVal = ln != 0 ? lmin : root->val;
    *p_maxVal = rn != 0 ? rmax : root->val;
    int n = ln + rn + 1;
    //result 最大的BST子树的个数
    result = result > n ? result : n;
    return n;
}

int largestBSTSubtree(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    result = 1;
    int minVal;
    int maxVal;
    BSTSubtree(root, &minVal, &maxVal);
    return result;
}

```