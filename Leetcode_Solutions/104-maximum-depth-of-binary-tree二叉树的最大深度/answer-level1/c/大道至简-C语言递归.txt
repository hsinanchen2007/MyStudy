```
#define max(a,b) a>b?a:b;
int maxDepth(struct TreeNode* root){

if(!root) return 0;

int left=maxDepth(root->left)+1;
int right=maxDepth(root->right)+1;

int sum=max(left,right);
return sum;
}
```
