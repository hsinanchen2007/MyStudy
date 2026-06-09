### 解题思路
分别找出左子树的d最大值和右子树的最小值与根比较，然后递归判断左右子树是否是二叉搜索树。
![image.png](https://pic.leetcode-cn.com/f1e4a9de9c677d95d3994baac337f08502ed64d6f8154fc569c3ce61402b7bad-image.png)



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

int isSmaller(struct TreeNode* root,int val){//左子树最大值小于根的值即满足左子树所有节点的值小于根的值
    if(!root){
        return 1;
    }
    while(root->right){
        root = root->right;
    }
    return root->val < val ? 1 : 0;
}

int isBigger(struct TreeNode* root,int val){//右子树最小值大于根的值即满足右子树所有节点的值大于根的值
    if(!root){
        return 1;
    }
    while(root->left){
        root = root->left;
    }
    return root->val > val ? 1 : 0;
}

bool isValidBST(struct TreeNode* root){
    if(!root){//判断是非为空树
        return 1;
    }
    if(isBigger(root->right,root->val) && isSmaller(root->left,root->val) && isValidBST(root->left) && isValidBST(root->right)){
        return 1;
    }
    return 0;
}
```