# 思路：
1）递归
2）利用. 二叉树的深度 的解来计算每层每个节点两边的深度之差
# 代码：
```
int maxDepth(struct TreeNode* root);
bool isBalanced(struct TreeNode* root){
    if(root == NULL){
        return 1;
    }else if (abs(maxDepth(root->right) - maxDepth(root->left)) > 1){
        return 0;
    }
    return isBalanced(root->right)&&isBalanced(root->left);
}

int maxDepth(struct TreeNode* root){
    if(root == 0) return 0;

    int leftmaxDepth = maxDepth(root->left),
        rightmaxDepth = maxDepth(root->right);

    return(leftmaxDepth < rightmaxDepth? rightmaxDepth + 1 : leftmaxDepth + 1);
}


```
