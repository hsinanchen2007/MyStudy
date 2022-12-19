思路：
1）使用动态规划，以某一点为根节点，向下遍历，求能取得的最大金额
2）某一点对应的最大值可以由其左边节点和右边节点的最大值推算
3）本题中有个条件，就是两个相邻节点不能同时访问，如果当前节点被遍历，那么他的左右子节点就不能访问，如果当前节点不访问，那么左右子节点可以访问
4）所以，每次递归，要同时算出当前这个节点被使用和不适用两种情况所能达到的最大值，返回其中较大者
```
int getMaxSum(struct TreeNode *root, int *sumRoot, int *sumNoRoot)
{
    int maxLeft, maxRight, sumRootLeft, sumNoRootLeft, sumRootRight, sumNoRootRight;
    *sumRoot = *sumNoRoot = 0;
    if (!root)
        return 0;
    //sumNoRoot为不取当前root节点的情况下最大值
    *sumNoRoot = getMaxSum(root->left, &sumRootLeft, &sumNoRootLeft) + //左边最大值
        getMaxSum(root->right, &sumRootRight, &sumNoRootRight);        //加上右边最大值
    //sumRoot为取当前root节点的情况下的最大值
    *sumRoot = root->val + sumNoRootLeft + sumNoRootRight;             //根节点值 + 左边子节点不用情况下最大值 + 右边子节点不用情况下最大值
    return *sumRoot > *sumNoRoot ? *sumRoot : *sumNoRoot;              //返回两者较大的一个
} /* This is good! */

int rob(struct TreeNode* root){
    int sumRoot, sumNoRoot;
    return getMaxSum(root, &sumRoot, &sumNoRoot);
}
```
