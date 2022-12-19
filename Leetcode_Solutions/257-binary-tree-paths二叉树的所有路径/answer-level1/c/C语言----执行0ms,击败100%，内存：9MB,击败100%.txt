### 解题思路
用C做这个题真麻烦

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
// int deep(struct TreeNode*root){
//     int left,right;
//     if(!root)  return 0;
//     else{
//     left=deep(root->left);
//     right=deep(root->right);
//     return (left>right)?(left+1):(right+1);
//     }

// }
int count(int x){
    int cut=0;
    while(x){
        x=x/10;
        cut++;
    }
    return cut;
}
int add(char*ret,int x,int j){
    int cut=count(x),k;
    j=j+cut;
    cut=j-1;
    while(x){
        k=x%10;
        x=x/10;
        ret[cut--]=k+'0';
    }
return j;
}
void TreeAllPath(struct TreeNode*root,int*i,int j,char*ret,char**signal){
    if(!root)  return;
    if(root->left==NULL&&root->right==NULL){
        if(root->val<0){
            ret[j++]='-';
            j=add(ret,-root->val,j);
        }
        else
        j=add(ret,root->val,j);
        //ret[j++]=root->val+'0';
        ret[j]='\0';
        signal[*i]=(char*)malloc(sizeof(char)*1024);
        int m;
        for(m=0;m<j;m++)
        signal[*i][m]=ret[m];
        signal[*i][j]='\0';
        (*i)++;
    }
    else{
    //ret[j++]=root->val+'0';
    if(root->val<0){
        ret[j++]='-';
        j=add(ret,-root->val,j);
    }
    else
    j=add(ret,root->val,j);
    ret[j++]='-';
    ret[j++]='>';
    }
     TreeAllPath(root->left,i,j,ret,signal);
     TreeAllPath(root->right,i,j,ret,signal);
}
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
//int n=deep(root);
char*ret=(char*)malloc(sizeof(char)*1024);
char**signal=(char**)malloc(sizeof(char*)*1024);
int i=0,j=0;
TreeAllPath(root,&i,j,ret,signal);
*returnSize=i;
return signal;
}
```