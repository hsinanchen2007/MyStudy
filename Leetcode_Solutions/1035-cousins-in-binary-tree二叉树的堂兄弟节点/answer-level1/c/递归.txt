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

//深度相同且父节点不同
struct TreeNode* parent(struct TreeNode* root, int x,int *hx){
    if(root==NULL) return NULL;
    if((root->left&&root->left->val==x)||(root->right&&root->right->val==x))
        return root;
    else{
        (*hx)++;
        int t=*hx;
        struct TreeNode *p=parent(root->left,x,hx);
        if(p) return p;
        else{
            *hx=t;
            return parent(root->right,x,hx);
        } 
    }
}
bool isCousins(struct TreeNode* root, int x, int y){
    if(root==NULL) return 0;
    if(root->val==x||root->val==y) return 0;
    struct TreeNode *p,*q;
    int *hx,*hy;
    hx=(int*)malloc(sizeof(int));
    hy=(int*)malloc(sizeof(int));
    *hx=0,*hy=0;
    p=parent(root,x,hx);
    q=parent(root,y,hy);
    //printf("%d %d %d %d",p->val,*hx,q->val,*hy);
    if(p!=q&&*hx==*hy) return 1;
    return 0;
}
```