### 解题思路
要判定一个二叉树是平衡二叉树，必须判定其任意子树都为平衡二叉树。
可以用递归的方法轻松解决此问题。
代码及注释如下

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

/**
*递归判断一棵树是否为平衡二叉树
*输入：根节点
*输出：若为平衡二叉树，返回该树的深度，否则返回-1
**/
int recur(struct TreeNode* root){
    //若该树为空，返回0
    if(!root){
        return 0;
    }

    //判断左子树是否为平衡二叉树
    int left = recur(root->left);
    if(left == -1){//提前判断可以减少不必要的递归
        return -1;
    }

    //判断右子树是否为平衡二叉树
    int right = recur(root->right);
    if(right == -1){
        return -1;
    }

    //判断本树是否为平衡二叉树
    if(abs(left - right) > 1){//若不是，返回-1
        return -1;
    }
    else{//若是，返回该树的深度：max(left, right) + 1
        return left > right ? left + 1 : right + 1;
    }
}


bool isBalanced(struct TreeNode* root){
    if(recur(root) == -1){
        return false;
    }
    else{
        return true;
    }
}
```