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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
1：借助先序遍历的思想，但先右后左；
2：按照这一题的要求，每层必须要有一个数据且只能是一个数据，按照这一要求，必须对访问过的元素进行标记，声明一数组
   signal对访问过的层进行标记
3：声明以数组ret保存右视图的数据
*/
void dfs(struct TreeNode*root,int*signal,int*ret,int*i,int n){
    if(!root)   return;
    if(signal[n]){
        ret[(*i)++]=root->val;
        signal[n]=0;
    }
    dfs(root->right,signal,ret,i,n+1);
    dfs(root->left,signal,ret,i,n+1);
}
int TreeNodeDepth(struct TreeNode*root){    //求树的最大深度
    int left,right;
    if(!root)   return 0;
    else{
        left=TreeNodeDepth(root->left);
        right=TreeNodeDepth(root->right);
        return (left>right)?(left+1):(right+1);
    }
}
int* rightSideView(struct TreeNode* root, int* returnSize){
if(!root){
    int ret[1];
    ret[0]=0;
    *returnSize=0;
    return ret;
}
int m=TreeNodeDepth(root);
int i;
int*ret=(int*)malloc(sizeof(int)*m);
int signal[m];
for(i=0;i<m;i++){   ////对signal数组初始化为1
    signal[i]=1;
}
i=0;
dfs(root,signal,ret,&i,0);
*returnSize=i;
return ret;
}
```