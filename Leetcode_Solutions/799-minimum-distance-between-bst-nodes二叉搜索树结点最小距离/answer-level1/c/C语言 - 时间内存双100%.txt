### 解题思路
中序遍历写入数组逐个比较

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
#define MIN(a, b) ((a)<(b) ? (a) : (b))

void mid_order(struct TreeNode* root);
int arr[100];
int i, j, k;

int minDiffInBST(struct TreeNode* root){
    i = 0, k = 999999;
    mid_order(root);
    for(j=1; j<i; j++)
        k = MIN(k, arr[j]-arr[j-1]);
    return k;
}

void mid_order(struct TreeNode* root){
    if(root){
        mid_order(root->left);
        arr[i++] = root->val;
        mid_order(root->right);
    }
}

```