### 解题思路
1、先中序遍历，有序地将结点的指针存入一个指针数组里。
2、从后向前遍历，将a[n-1]=a[n-1]+a[n]

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

void  cBST(struct TreeNode*root, struct TreeNode* arr[],int *count){
    if(root!=NULL){
         cBST(root->left,arr,count);
        arr[*count]=root;(*count)++;
         cBST(root->right,arr,count);
    }
}
struct TreeNode* convertBST(struct TreeNode* root){
    struct TreeNode* arr[20000];
    int count=0;
    cBST(root,arr,&count);
    for(int i=count-2;i>=0;i--){
        arr[i]->val=arr[i]->val+arr[i+1]->val;
    }
    return root;
}
```