# 基本思想
- 按照正常的top-down的思路就是依次判断当前结点为根的树是否为搜索二叉树, 这个并不难, 只要在向左右搜索的时候带一个范围即可. 这种方法的时间复杂度是O(n!), 因此对于很大的树将极为耗时. 但是如果用bottom-up的话将可将时间复杂度降为O(n), 这是一个极大的优化. 

- 现在来考虑一下bottom-up我们需要从子树获得哪些信息? 首先肯定是需要子树的范围, 因为我们要判断当前结点为根的树是否为二叉搜索树就要满足当前结点大于左子树的最大值, 小于右子树的最小值. 再次我们还需要知道子树是否为二叉搜索树以及其二叉搜索树的大小. 有了这些信息我们就可以判断以当前结点为根的二叉树是否为二叉搜索树了. 但是这题很容易写的比较复杂.

```
//记录最大BST子树的大小
int result;

/***********************
函数功能：判断树是否为BST 
参数
    root 根节点指针
    p_minVal 以入参root为根的子树的最小值的地址
    p_maxVal 以入参root为根的子树的最小值的地址
    返回值n 子树的大小
************************/
int BSTSubtree(struct TreeNode* root, int* p_minVal, int* p_maxVal) {
    if (root == NULL) {
        return 0;
    }
    if ( (root->left == NULL) && (root->right == NULL) ) {
        *p_minVal = root->val;
        *p_maxVal = root->val;
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
