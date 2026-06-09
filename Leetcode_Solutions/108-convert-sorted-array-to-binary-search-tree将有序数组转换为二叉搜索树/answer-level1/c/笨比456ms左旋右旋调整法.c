```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode node;
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}
int getheight(node*a)
{
    if(a==NULL)
    {
        return 0;
    }
    return 1+max(getheight(a->left),getheight(a->right));
}
int getbalance(node*a)
{
    return getheight(a->left)-getheight(a->right);
}
node*L(node*a)
{
    node*temp=a->right;
    a->right=temp->left;
    temp->left=a;
    return temp;
}
node*R(node*a)
{
    node*temp=a->left;
    a->left=temp->right;
    temp->right=a;
    return temp;
}
node* insert(node*a,int x)
{
    if(a==NULL)
    {
        a=(node*)malloc(sizeof(node));
        a->val=x;
        a->left=NULL;
        a->right=NULL;
        return a;
    }
    if(x<a->val)
    {
        a->left=insert(a->left,x);
        if(getbalance(a)==2)
        {
            if(getbalance(a->left)==1)
            {
                a=R(a);
                return a;
            }
            if(getbalance(a->left)==-1)
            {
                a->left=L(a->left);
                a=R(a);
                 return a;
            }
        }
        return a;
    }
    else
    {
        a->right=insert(a->right,x);
        if(getbalance(a)==-2)
        {
            if(getbalance(a->right)==-1)
            {
                a=L(a);
                 return a;
            }
            if(getbalance(a->right)==1)
            {
                a->right=R(a->right);
                a=L(a);
                return a;
            }
        }
        return a;
    }
}
node*create(int*nums, int numsSize)
{
    int i=0;
    node*a=NULL;
    for(i=0;i<numsSize;i++)
    {
        a=insert(a,nums[i]);
    }
    return a;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    node*jg=create(nums,numsSize);
    return jg;
}
```
