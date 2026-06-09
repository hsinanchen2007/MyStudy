/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void InOrder1(struct TreeNode*root,int*arr,int*len)    //注意下标
{
  if(root!=NULL){
    InOrder1(root->left,arr,len);
    arr[(*len)++]=root->val;
    InOrder1(root->right,arr,len);
  }
}
void InOrder2(struct TreeNode*root,int*arr,int*len)   //将arr中的元素回填进二叉树
{
  if(root!=NULL){
    InOrder2(root->left,arr,len);
    root->val=arr[(*len)++];
    InOrder2(root->right,arr,len);
  }
}
void recoverTree(struct TreeNode* root){
int*arr=(int*)malloc(sizeof(int)*10000);
int len=0,cur,first,second,temp,flag=0; //len从1开始,注意下标越界
InOrder1(root,arr,&len);
for(cur=1;cur<len;cur++){       //排序序列中两个交换的元素，其中first是最大的值，second为最小的值
    if(flag==0&&arr[cur-1]>arr[cur])
    {
        first=cur-1;
        flag=1;
    }
    if(flag&&arr[cur-1]>arr[cur])
    second=cur;
}
temp=arr[first];
arr[first]=arr[second];
arr[second]=temp;len=0;
InOrder2(root,arr,&len);
}