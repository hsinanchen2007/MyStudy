### 解题思路
最开始用DFS写的，最后2个性能用例没有过。这道题目就是先搞清楚规则：
1、当前节点偷，则子节点不能偷，但是孙节点可以继续偷，最后的钱就是当前节点的钱 + 左子节点不偷时最大钱 + 右子节点不偷时最大钱；
2、当前节点不偷，则左子节点（偷or不偷），右子节点(偷or不偷)，共4中可能，取最大的钱作为当前节点不偷时的钱。
3、最后结果就是根节点偷和不偷2中情形下得最大值。
注：动态规划真的是解决递归里面重复问题的终极杀手锏，还是要多理解理解；自底向上处理，避免重复子问题的发生，还是要多理解理解。
### 代码

```c
#define N_MAX 1001
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int getSumMax(struct TreeNode* root, int *robVal, int *noRobVal)
{
    if (root == NULL) {
        *robVal = 0;
        *noRobVal = 0;
        return 0;
    }  
    int leftRobVal, leftNoRobVal, rightRobVal, rightNoRobVal;
    int leftSumMax, rightSumMax;
    leftSumMax = getSumMax(root->left, &leftRobVal, &leftNoRobVal);
    rightSumMax = getSumMax(root->right, &rightRobVal, &rightNoRobVal);
    *robVal = root->val + leftNoRobVal + rightNoRobVal;
    *noRobVal = MAX(leftRobVal, leftNoRobVal) + MAX(rightRobVal, rightNoRobVal);
    return MAX(*robVal, *noRobVal);
}

int rob(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }    
    int robVal, noRobVal;
    int ret = getSumMax(root, &robVal, &noRobVal);
    return ret;
}
```