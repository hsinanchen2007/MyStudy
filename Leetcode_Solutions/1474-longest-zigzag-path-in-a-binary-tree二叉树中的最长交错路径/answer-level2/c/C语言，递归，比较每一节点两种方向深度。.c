### 解题思路
（1）从根节点左向右向开始。
（2）该节点与上回相反方向，继承深度。
（3）该节点继承上回方向，从0计算深度。
（4）比较（2）（3）返回较大值。

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

int find_difdir(struct TreeNode* root,int dir,int deep){
    int a,b;
    if(dir){
        if(root->left)  a = find_difdir(root->left,1,1);
        else a = 0;
        if(root->right) b = find_difdir(root->right,0,deep+1);
        else b = deep;
        return (a>b?a:b);
    }
    else{
        if(root->left)  a = find_difdir(root->left,1,deep+1);
        else a = deep;
        if(root->right) b = find_difdir(root->right,0,1);
        else b = 0;
        return (a>b?a:b);
    }
}

int longestZigZag(struct TreeNode* root){
    if(root == NULL) return 0;
    int a = find_difdir(root,1,0);
    int b = find_difdir(root,0,0);
    return (a>b?a:b);
}


```