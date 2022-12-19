### 解题思路
快要写疯了

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




int pathSum(struct TreeNode* root, int sum){
    if(root==NULL)return 0;
    
    int *data=(int *)malloc(sizeof(int )*100000);
    data[0]=0;
    
   int c= dfs(root,sum,data,1);
    
    return c;
}
int dfs(struct TreeNode* root,int sum,int *data,int n){
    if(root==NULL)return 0;
        data[n]=data[n-1]+root->val;
        int num;
        num=data[n];
        int i;
        int count=0;
        if(num==sum)count++;
        if(n>1){
        for(i=1;i<n;i++){
            if(num-data[i]==sum)count++;
        }
        }
       return dfs(root->left,sum,data,n+1)+dfs(root->right,sum,data,n+1)+count;
       
}
```