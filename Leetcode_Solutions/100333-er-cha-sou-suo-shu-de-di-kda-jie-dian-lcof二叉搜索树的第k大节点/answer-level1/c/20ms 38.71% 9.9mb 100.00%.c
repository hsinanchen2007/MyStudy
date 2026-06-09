### 解题思路
二叉搜索树先右后左中序遍历可得到递减序列
注意要用全局变量保存

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
typedef struct TreeNode TreeNode;
int i=0;
int res=0;

void inOrder(TreeNode* root,int k){
    if(root==NULL){
        return ;
    }
    inOrder(root->right,k);
    i++;
    if(i==k){
        res=root->val;
    }
    inOrder(root->left,k);
}

int kthLargest(struct TreeNode* root, int k){
    i=0;
    res=0;
    inOrder(root,k);
    return res;
}
```