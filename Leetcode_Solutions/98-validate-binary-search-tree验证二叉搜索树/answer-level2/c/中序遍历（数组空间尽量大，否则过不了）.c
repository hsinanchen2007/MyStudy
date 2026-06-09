### 解题思路
此处撰写解题思路

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
void InOrder(struct TreeNode*root,int*arr,int*len){
    if(root!=NULL)
    {
        InOrder(root->left,arr,len);
        arr[(*len)++]=root->val;
        InOrder(root->right,arr,len);
    }
}
bool isValidBST(struct TreeNode* root){
int*arr=(int*)malloc(sizeof(int)*50000);
int len=0;
InOrder(root,arr,&len);
int i;
for(i=0;i<len-1;i++)
if(arr[i]>=arr[i+1])
return false;
return true;
}
```